var getCookie, getCookiesHistory, getLocalStorageHistory, pages, setCookie;

pages = ['Главная', 'Обо мне', 'Мои интересы', 'Учеба', 'Фотоальбом', 'Контакт', 'Тест', 'История'];

getLocalStorageHistory = function() {
  var i, localStorageTable;
  localStorageTable = document.getElementById('localStorageTable');
  i = 0;
  while (i < pages.length) {
    localStorageTable.innerHTML += `<tr><th scope='row'>${i + 1}</th><td>${pages[i]}</td><td>${(sessionStorage.getItem(pages[i]) ? sessionStorage.getItem(pages[i]) : 0)}</td></tr>`;
    i++;
  }
};

getCookiesHistory = function() {
  var cookieTable, i;
  cookieTable = document.getElementById('cookieTable');
  i = 0;
  while (i < pages.length) {
    cookieTable.innerHTML += `<tr><th scope='row'>${i + 1}</th><td>${pages[i]}</td><td>${(getCookie(pages[i]) ? getCookie(pages[i]) : 0)}</td></tr>`;
    i++;
  }
};

getCookie = function(cname) {
  var c, ca, decodedCookie, i, name;
  name = cname + '=';
  decodedCookie = decodeURIComponent(document.cookie);
  ca = decodedCookie.split(';');
  i = 0;
  while (i < ca.length) {
    c = ca[i];
    while (c.charAt(0) === ' ') {
      c = c.substring(1);
    }
    if (c.indexOf(name) === 0) {
      return c.substring(name.length, c.length);
    }
    i++;
  }
  return '';
};

setCookie = function(cname, cvalue, exdays) {
  var d, expires;
  d = new Date;
  d.setTime(d.getTime() + exdays * 24 * 60 * 60 * 1000);
  expires = 'expires=' + d.toUTCString();
  document.cookie = cname + '=' + cvalue + ';' + expires + ';path=/';
};

document.addEventListener('DOMContentLoaded', function() {
  var title;
  title = document.title.substring(10);
  sessionStorage.setItem(title, +sessionStorage.getItem(title) + 1);
  setCookie(title, +getCookie(title) + 1, 30);
});
