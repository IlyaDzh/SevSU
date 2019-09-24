var interestsList = [
    { id: "#films", text: "Фильмы" },
    { id: "#music", text: "Музыка" },
    { id: "#books", text: "Книги" },
    { id: "#race", text: "Спорт" },
    { id: "#games", text: "Игры" }
]

function interests(interes) {
    var interestHtml = "";
    for (var i = 0; i < interes.length; i++) {
        interestHtml += `<li class='nav-item'><a class='nav-link active' href='${interes[i].id}'>${interes[i].text}</a></li>`;
    }
    return interestHtml;
}

function viewInterests() {
    var view = document.getElementById("interests");
    view.innerHTML = interests(interestsList);
}