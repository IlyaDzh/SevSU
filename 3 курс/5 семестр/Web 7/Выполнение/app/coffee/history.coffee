pages = [
  'Главная'
  'Обо мне'
  'Мои интересы'
  'Учеба'
  'Фотоальбом'
  'Контакт'
  'Тест'
  'История'
]

getLocalStorageHistory = ->
  localStorageTable = document.getElementById('localStorageTable')
  i = 0
  while i < pages.length
    localStorageTable.innerHTML += "<tr><th scope='row'>#{i + 1}</th><td>#{pages[i]}</td><td>#{if sessionStorage.getItem(pages[i]) then sessionStorage.getItem(pages[i]) else 0}</td></tr>"
    i++
  return

getCookiesHistory = ->
  cookieTable = document.getElementById('cookieTable')
  i = 0
  while i < pages.length
    cookieTable.innerHTML += "<tr><th scope='row'>#{i + 1}</th><td>#{pages[i]}</td><td>#{if getCookie(pages[i]) then getCookie(pages[i]) else 0}</td></tr>"
    i++
  return

getCookie = (cname) ->
  name = cname + '='
  decodedCookie = decodeURIComponent(document.cookie)
  ca = decodedCookie.split(';')
  i = 0
  while i < ca.length
    c = ca[i]
    while c.charAt(0) == ' '
      c = c.substring(1)
    if c.indexOf(name) == 0
      return c.substring(name.length, c.length)
    i++
  ''

setCookie = (cname, cvalue, exdays) ->
  d = new Date
  d.setTime d.getTime() + exdays * 24 * 60 * 60 * 1000
  expires = 'expires=' + d.toUTCString()
  document.cookie = cname + '=' + cvalue + ';' + expires + ';path=/'
  return

document.addEventListener 'DOMContentLoaded', ->
  title = document.title.substring(10)
  sessionStorage.setItem title, +sessionStorage.getItem(title) + 1
  setCookie title, +getCookie(title) + 1, 30
  return