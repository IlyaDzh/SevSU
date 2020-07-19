<!doctype html>
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
    <nav class="navbar navbar-expand-md navbar-dark sticky-top" style="background-color: #563d7c">
        <div class="container">
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbar" aria-controls="navbar" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbar">
                <ul class="navbar-nav">
                    <li class="nav-item">
                        <a class="nav-link {{ Request::is('/') ? 'active' : '' }}" href="{{ route('main') }}">Главная</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link {{ Request::is('about') ? 'active' : '' }}" href="{{ route('about') }}">Обо мне</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link {{ Request::is('blog') ? 'active' : '' }}" href="{{ route('posts.index') }}">Мой блог</a>
                    </li>
                </ul>
                <ul class="navbar-nav ml-auto">
                    @if (!auth()->check())
                        <li class="nav-item">
                            <a class="nav-link {{ Request::is('login') ? 'active' : '' }}" href="{{ route('login') }}">Вход</a>
                        </li>
                    @else
                        <li class="nav-item">
                            <div class="nav-link active">Пользователь: {{ Auth::user()->name }}</div>
                        </li>
                    @endif

                    @if (!auth()->check())
                        <li class="nav-item">
                            <a class="nav-link {{ Request::is('register') ? 'active' : '' }}" href="{{ route('register') }}">Регистрация</a>
                        </li>
                    @else
                        <li class="nav-item">
                            <a class="nav-link {{ Request::is('logout') ? 'active' : '' }}" href="{{ url('/logout') }}">Выход</a>
                        </li>
                    @endif
                </ul>
            </div>
        </div>
    </nav>
    
    @yield('content')
    
</body>

</html>