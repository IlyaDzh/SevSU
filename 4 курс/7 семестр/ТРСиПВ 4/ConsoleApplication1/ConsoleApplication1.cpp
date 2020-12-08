#include <iostream>
#include <time.h>
#include <Windows.h>
#include "mpi.h"

using namespace std;

// Тэг для обмена между клиентами и сервером
#define CLIENT_SERVER_MSG_TAG 99

// Общее кол-во заявок на ресурс
#define MAX_MESSAGES 10

const int countResources = 3;

int main(int argc, char* argv[])
{
	int rank, processes;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &processes);
	MPI_Status status;

	int serverProcess = 0;
	int resourceProcess = 3;

	// Клиент, запросивший ресурс, указывает номер необходимого ресурса в эту переменную
	int message[1];

	if (rank == serverProcess)
	{
		cout << "Server started" << endl;
		cout << "____________________________________________________________" << endl;

		// Результат ответа от ресурсного процесса, т.е. запрошенный ресурс для клиента
		int result[1];

		MPI_Status status;

		for (size_t i = 0; i < MAX_MESSAGES; i++)
		{
			// Ожидаем поступления сообщения от клиентов
			// т.к. перед приемом сообщения нам необходимо знать номер процесса, который к нам обращается,
			// то мы с помощью фукции зондирования входящих сообщений Probe узнаем номер источника сообщения
			MPI_Probe(MPI_ANY_SOURCE, CLIENT_SERVER_MSG_TAG, MPI_COMM_WORLD, &status);

			// Узнаем номер входящего процесса из полученной с помощью зондирования информации
			int client = status.MPI_SOURCE;

			// Зная номер процесса, отправившего нам сообщение, можем принять его
			MPI_Recv(&message, 1, MPI_INT, client, CLIENT_SERVER_MSG_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

			// Полученное сообщение мы помещаем в переменную _message,
			// в которую клиентский процесс, запросивший ресурс, указывает номер необходимого ресурса
			// Выводим сообщение о том, что клиентский процесс с номером "client"
			// запрашивает ресурс с номером, указанным в теле сообщения
			cout << "\nServer : processing the client " << client << "th accessing the resource " << message[0] + 1 << endl;
			cout << "-------------------------------------------------------------------------" << endl;

			// Отправляем сообщение ресурсу и в теле сообщения указываем номер ресурса, который нам неообходим
			MPI_Send(message, 1, MPI_INT, resourceProcess, 88, MPI_COMM_WORLD);

			// Ожидаем ответа от ресурсного процесса
			MPI_Recv(result, 1, MPI_INT, resourceProcess, 88, MPI_COMM_WORLD, &status);

			cout << "\nServer : receive resourse " << result[0] << " from resourse process" << endl;

			// Отправка запрошенного ресура _result клиенту "client"
			MPI_Send(result, 1, MPI_INT, client, CLIENT_SERVER_MSG_TAG, MPI_COMM_WORLD);

			// Получение подтверждения от клиента об освобождении ресурса
			MPI_Recv(&message, 1, MPI_INT, client, CLIENT_SERVER_MSG_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

			// Признаком освобождения ресурса является сообщение,
			// в котором в качестве тела запроса указывается -99 (-CLIENT_SERVER_MSG_TAG)
			if (message[0] == -CLIENT_SERVER_MSG_TAG)
			{
				cout << "\nServer : " << client << "th client free resource" << endl;
			}
		}
	}
	else if (rank == resourceProcess)
	{
		/*
			resource[0] - общая сумма от продажи товаров
			resource[1] - общее кол-во товаров
			resource[2] - общее кол-во остальных товаров
		*/
		int resource[countResources];
		resource[0] = 524334;
		resource[1] = 3233;
		resource[2] = 232;

		// Номер необходимого ресурса, который будет указан в сообщении от сервера
		int numResource[1];

		// Необходимый ресурс и отправим его в теле сообщения к серверу
		int result[1];

		for (int i = 0; i < MAX_MESSAGES; ++i)
		{
			// Ждем поступления сообщения от сервера
			// С помощью фукции зондирования входящих сообщений Probe узнаем, поступило нам сообщение или нет
			// Выход из функции Probe произойдет, как только поступит сообщение
			MPI_Status status;
			MPI_Probe(MPI_ANY_SOURCE, 88, MPI_COMM_WORLD, &status);

			// Принимаем сообщение от сервера с номером необходимого ресурса _num_resource
			MPI_Recv(numResource, 1, MPI_INT, serverProcess, 88, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

			cout << "\nResource : receive request from server for giving resource number " << numResource[0] + 1 << endl;

			// В тело ответного сообщения поместим необходимый ресурс и отправим его в теле сообщения к серверу
			result[0] = resource[numResource[0]];

			cout << "\nResource : send to server resource number " << numResource[0] + 1 << " = " << result[0] << endl;

			// Отправка ответа серверу с необходимым ресурсом
			MPI_Send(result, 1, MPI_INT, serverProcess, 88, MPI_COMM_WORLD);
		}
	}
	else if (rank == 1 || rank == 2)
	{
		// Генератор случайных чисел для выбора случайного номера ресурса от 1 до countResources
		srand(time(0));
		int rez[1];

		// Определяем кол-во запросов, которое клиент отправит серверу
		// для простоты, MAX_MESSAGES = 10. processes = общее кол-во процессов.
		// и того каждый из клиентов отправит по 5 сообщений на запрос ресурса
		int countMessageForClient = (MAX_MESSAGES) / (processes - 2);

		// Цикл на отправку сообщений клиентов к серверу
		for (size_t i = 0; i < countMessageForClient; i++)
		{
			// Случайно выбираем номер ресурса
			int num_resource = rand() % countResources;

			// Сообщение клиента о том, что он будет отправлять серверу запрос на ресурс с номером num_resource
			cout << "Client " << rank << ": requests resource number " << num_resource + 1 << endl;

			// Помещаем в тело сообщения номер ресурса, который нам необходим
			message[0] = num_resource;

			// Отправка сообщения с запросом серверу
			MPI_Send(message, 1, MPI_INT, serverProcess, CLIENT_SERVER_MSG_TAG, MPI_COMM_WORLD);

			// Получение ответа от сервера с запрошенным ресурсом
			MPI_Recv(rez, 1, MPI_INT, serverProcess, CLIENT_SERVER_MSG_TAG, MPI_COMM_WORLD, &status);

			// Сообщение от клиента о получении ресурса rez, полученного от сервера
			cout << "Client " << rank << ": receive resource " << rez[0] << endl;

			// Задержка обработку ресура
			Sleep((DWORD)1000);

			// Помещаем в тело сообщения тег -99 (-CLIENT_SERVER_MSG_TAG),
			// который будет обозначать, что мы освободили этот ресурс
			// и он может быть выдан следующему клиенту
			message[0] = -CLIENT_SERVER_MSG_TAG;

			// Отправка сообщения серверу об освобождении ресурса
			MPI_Send(message, 1, MPI_INT, serverProcess, CLIENT_SERVER_MSG_TAG, MPI_COMM_WORLD);
		}
	}

	MPI_Finalize();

	return 0;
}