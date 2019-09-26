interests = [
    {
        id: '#films'
        text: 'Фильмы'
    }
    {
        id: '#music'
        text: 'Музыка'
    }
    {
        id: '#books'
        text: 'Книги'
    }
    {
        id: '#race'
        text: 'Спорт'
    }
    {
        id: '#games'
        text: 'Игры'
    }
]
for interest in interests
    document.writeln "<li class='nav-item'><a class='nav-link active' href=#{interest.id}>#{interest.text}</a></li>"