@extends('layout.header')

@section('title', 'Главная')

@section('content')

<section class="main-content container">
    <div class="lab-work mt-5">
        <h4 class="lab__number">Лабораторная работа №11:</h4>
        <h5 class="lab__name">
            "Исследование возможностей фреймворка Laravel для разработки веб-приложений"
        </h5>
    </div>
    <div class="main-image">
        <img src="{{ asset('img/photo-main.jpg') }}" class="main__photo" alt="My photo">
    </div>
    <h1 class="main__fio">Долженко Илья Андреевич</h1>
    <h2 class="main__group">ИС-17-2</h2>
</section>

@endsection('content')