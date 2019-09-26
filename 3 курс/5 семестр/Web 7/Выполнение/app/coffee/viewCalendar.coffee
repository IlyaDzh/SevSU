viewCalendar = ->
  date = new Date
  nowDate = daysInMonth(date.getMonth() + 1, date.getFullYear())
  document.writeln '<tr>'
  i = 1
  while i < nowDate + 1
    document.writeln "<td><a href='#'>#{i}</a></td>"
    document.writeln '</tr><tr>' if i % 7 == 0
    i++
  document.writeln '</tr>'
  upateVariable()
  return

daysInMonth = (month, year) ->
  new Date(year, month, 0).getDate()

updateCalendar = ->
  tbody = document.getElementById('tbodyCalendar')
  years = document.getElementById('years')
  month = document.getElementById('month')
  yearsValue = years.options[years.selectedIndex].text
  monthValue = month.selectedIndex
  date = new Date(yearsValue, monthValue)
  nowDate = daysInMonth(date.getMonth(), date.getFullYear())
  tr = document.createElement('tr')
  tbody.innerHTML = ''
  i = 1
  while i < nowDate + 1
    td = document.createElement('td')
    a = document.createElement('a')
    a.setAttribute 'href', '#'
    textnode = document.createTextNode(i)
    a.appendChild textnode
    td.appendChild a
    tr.appendChild td
    if i % 7 == 0
      tbody.appendChild tr
      tr = document.createElement('tr')
    if i == nowDate
      tbody.appendChild tr
    i++
  upateVariable()
  return