import re

index = -1
consts = {}


# декоратор
def decorator_function(func):
  def wrapper(*args, **kwargs):
    try:
      global index
      index += 1
      return func(*args, **kwargs)
    except Exception as e:
      return 0
  wrapper.__name__ = func.__name__
  return wrapper


def read_consts(name_file):
  consts = {}
  with open(name_file) as file:
    for line in file:
      key, value, msg = line.split('\t')
      msg = msg.replace('\n', '')
      consts[key] = {
        'code': int(value),
        'msg': msg.encode('cp1251').decode('utf-8')
      }
  return consts


@decorator_function
def check(data, const):
  if data[index] == const['code']:
    return 1
  else:
    print("\t{}".format(const['msg']))
    return 0


@decorator_function
def S_fragment (data):
  global index
  index = -1
  return S_identif(data) *\
         check(data, consts['Semicolon']) * \
         check(data, consts['FUNC']) * \
         check(data, consts['Bracket_open']) * \
         S_arg(data) * \
         check(data, consts['Bracket_close']) * \
         check(data, consts['Division']) * \
         S_telo_prog(data) * \
         check(data, consts['FINAL'])


@decorator_function
def S_identif(data):
  if data[index] == consts['Iden']['code']:
    return 1
  else:
    print("\tожидался идентификатор")
    return 0


@decorator_function
def S_arg(data):
  if data[index] == consts['Data']['code']:
    return 1
  else:
    print("\tожидался аргумент")
    return 0


@decorator_function
def S_telo_prog(data):
  if data[index] == consts['Brace_open']['code']:
    return S_operatori(data)
  else:
    print("\tожидалось тело программы")
    return 0


@decorator_function
def S_operatori(data):
  global index
  if data[index] == consts['Brace_close']['code']:
    return 1
  else:
    index -= 1
    return S_operator(data) * S_operatori(data)


@decorator_function
def S_operator(data):
  if data[index] == consts['Iden']['code']:
    return check(data, consts['Prisv']) * \
           S_initcializator(data) * \
           check(data, consts['Division'])
  else:
    print("\tожидался oператор")
    return 0


@decorator_function
def S_initcializator(data):
  global index
  if data[index] == consts['Exclamation_mark']['code']:
    return S_expression(data)
  else:
    index -= 1
    return S_expression(data)


@decorator_function
def S_expression(data):
  global index
  if data[index] == consts['Bracket_open']['code']:
    return S_operand(data) * S_end_expression(data)
  else:
    print("\tожидалось выражение")
    return 0


@decorator_function
def S_operand (data):
  if data[index] == consts['Iden']['code']:
    return 1
  elif data[index] == consts['Data']['code']:
    return 1
  else:
    print("\tожидался операнд")
    return 0


@decorator_function
def S_end_expression(data):
  if data[index] == consts['Exclamation_mark']['code'] or \
     data[index] == consts['Dounbel_exclamation_mark']['code'] or \
     data[index] == consts['Double_and']['code']:
    return S_operand(data) * S_end_expression(data)
  elif data[index] == consts['Bracket_close']['code']:
    return 1
  else:
    print("\tожидался конец выражения")
    return 0


def main():
  global consts, index
  consts = read_consts('D:\data.txt')

  test_data = []
  with open('D:/test_data.txt') as file_handle:
    for line in file_handle:
      test_data.append([int(x) for x in line.split()])

  i = 0
  for test in test_data:
    i += 1
    print("\nЦепочка №{}:".format(i))
    index = -1
    try:
      if S_fragment(test) == 0:
          print("\tСинтаксическая ошибка")
      else: print("\tЦепочка верна")
    except Exception as e:
      print(str(e))
      print("\tСинтаксическая ошибка")


main()