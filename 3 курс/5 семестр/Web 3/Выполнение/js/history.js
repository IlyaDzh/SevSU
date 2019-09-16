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
    localStorage.setItem(title, +localStorage.getItem(title) + 1);
});

function getLocalStorageHistory() {
    localStorageTable = document.getElementById("localStorageTable");
    for (let i = 0; i < pages.length; i++) {
        localStorageTable.innerHTML +=
            `<tr>
            <th scope="row">${i}</th>
            <td>${pages[i]}</td>
            <td>${localStorage.getItem(pages[i])}</td>
        </tr>`;
    }
}