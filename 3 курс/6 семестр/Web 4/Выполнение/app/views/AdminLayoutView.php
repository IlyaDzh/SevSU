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
                        <a class="nav-link <?php if ($title == "Редактор блога") echo('menu-link-active') ?>" href="/admin/editblog">Редактор блога</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if ($title == "Загрузка отзывов") echo('menu-link-active') ?>" href="/admin/uploadreviews">Загрузка отзывов</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if ($title == "Загрузка постов блога") echo('menu-link-active') ?>" href="/admin/uploadposts">Загрузка постов блога</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link <?php if ($title == "Статистика посещений") echo('menu-link-active') ?>" href="/admin/statistics">Статистика посещений</a>
                    </li>
                </ul>
                <ul class="navbar-nav ml-auto">
                    <li class="nav-item">
                        <?php 
                            if (isset($_SESSION['isAdmin'])) { 
                        ?>
                                <a class="nav-link" href="/admin/auth/logout">Выход</a>
                        <?php 
                            } else { 
                        ?>
                                <a class="nav-link <?php if ($title == "Вход") echo('menu-link-active') ?>" href="/admin/auth">Вход</a>
                        <?php 
                            }
                        ?>
                    </li>
                </ul>
            </div>
        </div>
    </nav>

    <?php 
        include 'app/views/admin/' . $content_view;  
    ?>
</body>

</html>