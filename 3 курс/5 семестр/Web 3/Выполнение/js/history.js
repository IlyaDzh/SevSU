const pages = [
    'Главная',
    'Обо мне',
    'Мои интересы',
    'Учеба',
    'Фотоальбом',
    'Контакт',
    'Тест',
    'История'
];

document.addEventListener('DOMContentLoaded', () => {
    var title = document.title.substring(10);
    sessionStorage.setItem(title, +sessionStorage.getItem(title) + 1);
    setCookie(title, getCookie(title) ? +getCookie(title) + 1 : 0, 30);
});

function getLocalStorageHistory() {
    localStorageTable = document.getElementById("localStorageTable");
    for (let i = 0; i < pages.length; i++) {
        localStorageTable.innerHTML +=
            `<tr>
            <th scope="row">${i + 1}</th>
            <td>${pages[i]}</td>
            <td>${sessionStorage.getItem(pages[i]) ? sessionStorage.getItem(pages[i]) : 0}</td>
        </tr>`;
    }
}

function getCookiesHistory() {
    cookieTable = document.getElementById("cookieTable");
    for (let i = 0; i < pages.length; i++) {
        cookieTable.innerHTML +=
            `<tr>
            <th scope="row">${i + 1}</th>
            <td>${pages[i]}</td>
            <td>${getCookie(pages[i])}</td>
        </tr>`;
    }
}

function getCookie(cname) {
    var name = cname + "=";
    var decodedCookie = decodeURIComponent(document.cookie);
    var ca = decodedCookie.split(';');
    for (var i = 0; i < ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) == ' ') {
            c = c.substring(1);
        }
        if (c.indexOf(name) == 0) {
            return c.substring(name.length, c.length);
        }
    }
    return "";
}

function setCookie(cname, cvalue, exdays) {
    var d = new Date();
    d.setTime(d.getTime() + (exdays * 24 * 60 * 60 * 1000));
    var expires = "expires=" + d.toUTCString();
    document.cookie = cname + "=" + cvalue + ";" + expires + ";path=/";
}