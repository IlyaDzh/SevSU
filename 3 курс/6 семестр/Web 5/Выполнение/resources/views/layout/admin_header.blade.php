<!DOCTYPE html>
<html lang="ru">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="csrf-token" content="{{ csrf_token() }}">
    <title>@yield('title')</title>
    <link href="{{ asset('css/bootstrap.min.css') }}" rel="stylesheet">
    <link href="{{ asset('css/main.css') }}" rel="stylesheet">
</head>

<body>
    <nav class="navbar navbar-expand-lg navbar-dark sticky-top" style="background-color: #563d7c">
        <div class="container">
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbar"
                aria-controls="navbar" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbar">
                <ul class="navbar-nav">
                    <li class="nav-item">
                        <a class="nav-link {{ Request::is('/admin/editblog') ? 'active' : '' }}" href="/admin/editblog">Редактор блога</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link {{ Request::is('/admin/statistics') ? 'active' : '' }}" href="/admin/statistics">Статистика посещений</a>
                    </li>
                </ul>
                <ul class="navbar-nav ml-auto">
                    <li class="nav-item">
                        <a class="nav-link {{ Request::is('/admin/auth') ? 'active' : '' }}" href="/admin/auth">Вход</a>
                    </li>
                </ul>
            </div>
        </div>
    </nav>

    @yield('content')
    
</body>

</html>