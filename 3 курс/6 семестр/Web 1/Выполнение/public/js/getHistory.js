const pages = [
    "Главная",
    "Обо мне",
    "Мои интересы",
    "Учеба",
    "Фотоальбом",
    "Контакт",
    "Тест",
    "История"
];

function getLocalStorageHistory() {
    localStorageTable = document.getElementById("localStorageTable");
    for (let i = 0; i < pages.length; i++) {
        localStorageTable.innerHTML += `
            <tr>
                <th scope="row">${i + 1}</th>
                <td>${pages[i]}</td>
                <td>${
                    sessionStorage.getItem(pages[i])
                        ? sessionStorage.getItem(pages[i])
                        : 0
                }</td>
            </tr>
        `;
    }
}

function getCookiesHistory() {
    cookieTable = document.getElementById("cookieTable");
    for (let i = 0; i < pages.length; i++) {
        cookieTable.innerHTML += `
            <tr>
                <th scope="row">${i + 1}</th>
                <td>${pages[i]}</td>
                <td>${getCookie(pages[i]) ? getCookie(pages[i]) : 0}</td>
            </tr>
        `;
    }
}

getLocalStorageHistory();
getCookiesHistory();
