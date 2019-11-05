using System;

namespace ConsoleApp2
{
    class ValueException : Exception
    {
        new public string Message { get; set; }
        public ValueException(FieldType fieldType)
        {
            switch (fieldType)
            {
                case FieldType.Name:
                    Message = "Поле ФИО не может быть изменено";
                    break;
                case FieldType.Date:
                    Message = "Поле Дата не может быть пустым";
                    break;
                case FieldType.Questions:
                    Message = "Поле Вопросы не корректное";
                    break;
                default:
                    Message = "Неизвестное поле";
                    break;
            }
        }
    }

    enum FieldType
    {
        Name,
        Date,
        Questions
    }
}