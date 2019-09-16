var interests = [
    { id: "#films", text: "Фильмы" },
    { id: "#music", text: "Музыка" },
    { id: "#books", text: "Книги" },
    { id: "#race", text: "Спорт" },
    { id: "#games", text: "Игры" }
]

for (var i = 0; i < interests.length; i++) {
    document.writeln(`<li class='nav-item'><a class='nav-link active' href='${interests[i].id}'>${interests[i].text}</a></li>`);
}