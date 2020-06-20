<!DOCTYPE html>
<html lang="ru">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title><?php echo $title; ?></title>
    <link rel="icon" href="img/icon.ico">
    <link href="https://fonts.googleapis.com/css?family=Montserrat:400,400i,500,500i,600,600i,700&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="/public/css/bootstrap.min.css">
    <link rel="stylesheet" href="/public/css/main.css">
    <script src="/public/js/setHistory.js"></script>
</head>

<body>
    <nav class="navbar navbar-expand-lg navbar-dark sticky-top" style="background-color:#563d7c">
        <div class="container">
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbar1"
                aria-controls="navbar1" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbar1">
                <ul class="navbar-nav">
                    <li class="nav-item">
                        <a class="nav-link <?php if ($title == "Главная") echo('menu-link-active') ?>" href="/">Главная</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if ($title == "Обо мне") echo('menu-link-active') ?>" href="/about">Обо мне</a>
                    </li>
                    <li class="nav-item dropdown" id="drop">
                        <a class="nav-link dropdown-toggle <?php if ($title == "Мои интересы") echo('menu-link-active') ?>" 
                            id="dropdown_menu" href="hobby">Мои интересы</a>
                        <ul class="dropdown-menu" id="menu-list">
                            <li><a class="dropdown-item" href="hobby#films">Фильмы</a></li>
                            <li><a class="dropdown-item" href="hobby#music">Музыка</a></li>
                            <li><a class="dropdown-item" href="hobby#books">Книги</a></li>
                            <li><a class="dropdown-item" href="hobby#sport">Спорт</a></li>
                            <li><a class="dropdown-item" href="hobby#games">Игры</a></li>
                        </ul>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if ($title == "Учеба") echo('menu-link-active') ?>" href="/studies">Учеба</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if ($title == "Фотоальбом") echo('menu-link-active') ?>" href="/photo">Фотоальбом</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if ($title == "Контакт") echo('menu-link-active') ?>" href="/contact">Контакт</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if ($title == "Тест") echo('menu-link-active') ?>" href="/test">Тест</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if ($title == "История") echo('menu-link-active') ?>" href="/history">История</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if ($title == "Гостевая книга") echo('menu-link-active') ?>" href="/guestbook">Гостевая книга</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if ($title == "Мой блог") echo('menu-link-active') ?>" href="/blog">Мой блог</a>
                    </li>
                    <li class="nav-item dropdown" id="edit-dropdown">
                        <div class="nav-link dropdown-toggle <?php if ($title == "Загрузка отзывов" || $title == "Редактор блога" || $title == "Загрузка постов блога") echo('menu-link-active') ?>">Редактирование</div>
                        <ul class="dropdown-menu">
                            <li class="nav-item">
                                <a class="dropdown-item <?php if ($title == "Редактор блога") echo('menu-link-active') ?>" href="/editblog">Редактор блога</a>
                            </li>
                            <li class="nav-item">
                                <a class="dropdown-item <?php if ($title == "Загрузка отзывов") echo('menu-link-active') ?>" href="/uploadreviews">Загрузка отзывов</a>
                            </li>
                            <li class="nav-item">
                                <a class="dropdown-item <?php if ($title == "Загрузка постов блога") echo('menu-link-active') ?>" href="/uploadposts">Загрузка постов блога</a>
                            </li>
                        </ul>
                    </li>
                </ul>
            </div>
        </div>
    </nav>

    <?php 
        include 'app/views/' . $content_view;  
    ?>

    <script src="/public/js/dropdown.js"></script>
</body>

</html>