<!DOCTYPE html>
<html lang="ru">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title><?php echo $title; ?></title>
    <link rel="icon" href="img/icon.ico">
    <link href="https://fonts.googleapis.com/css?family=Montserrat:400,400i,500,500i,600,600i,700&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="public/css/bootstrap.min.css">
    <link rel="stylesheet" href="public/css/main.css">
    <?php 

    if ($header_scripts) {
        foreach($header_scripts as $script) {
            echo "<script src='public/js/$script'></script>";
        }
    }

    ?>
</head>

<body>
    <nav class="navbar navbar-expand-lg navbar-dark sticky-top" style="background-color:#563d7c">
        <div class="container">
            <div class="timer" id="time"></div>
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbar1"
                aria-controls="navbar1" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbar1">
                <ul class="navbar-nav ml-auto">
                    <li class="nav-item">
                        <a class="nav-link <?php if($active == "Главная") echo('menu-link-active') ?>" href="index.php">Главная</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if($active == "Обо мне") echo('menu-link-active') ?>" href="about.php">Обо мне</a>
                    </li>
                    <li class="nav-item dropdown" id="drop">
                        <a class="nav-link dropdown-toggle <?php if($active == "Мои интересы") echo('menu-link-active') ?>" 
                            id="dropdown_menu" href="entertainment.php">Мои интересы</a>
                        <ul class="dropdown-menu" id="menu-list">
                            <li><a class="dropdown-item" href="entertainment.php#films">Фильмы</a></li>
                            <li><a class="dropdown-item" href="entertainment.php#music">Музыка</a></li>
                            <li><a class="dropdown-item" href="entertainment.php#books">Книги</a></li>
                            <li><a class="dropdown-item" href="entertainment.php#sport">Спорт</a></li>
                            <li><a class="dropdown-item" href="entertainment.php#games">Игры</a></li>
                        </ul>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if($active == "Учеба") echo('menu-link-active') ?>" href="studies.php">Учеба</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if($active == "Фотоальбом") echo('menu-link-active') ?>" href="photo.php">Фотоальбом</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if($active == "Контакт") echo('menu-link-active') ?>" href="contact.php">Контакт</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if($active == "Тест") echo('menu-link-active') ?>" href="test.php">Тест</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if($active == "История") echo('menu-link-active') ?>" href="history.php">История</a>
                    </li>
                </ul>
            </div>
        </div>
    </nav>