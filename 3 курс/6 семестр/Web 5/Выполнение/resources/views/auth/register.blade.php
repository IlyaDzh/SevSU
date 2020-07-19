@extends('layout.header')

@section('content')
<section class="content container">
    <div class="row justify-content-center">
        <div class="col-lg-4 text-center">
            <h3 class="mb-4">Регистрация</h3>
            <form method="POST" action="{{ route('register') }}" class="mb-4">
                @csrf

                <div class="form-group">
                    <input id="name" type="text" class="form-control @error('name') is-invalid @enderror" name="name" value="{{ old('name') }}" placeholder="Введите ФИО" autocomplete="name" required autofocus>
                    @error('name')
                        <span class="invalid-feedback" role="alert">
                            <strong>{{ $message }}</strong>
                        </span>
                    @enderror                
                </div>
                <div class="form-group">
                    <input id="email" type="email" class="form-control @error('email') is-invalid @enderror" name="email" value="{{ old('email') }}" placeholder="Введите E-mail" autocomplete="email" required>
                    @error('email')
                        <span class="invalid-feedback" role="alert">
                            <strong>{{ $message }}</strong>
                        </span>
                    @enderror
                </div>
                <div class="form-group">
                    <input id="password" type="password" class="form-control @error('password') is-invalid @enderror" name="password" placeholder="Введите пароль" autocomplete="new-password" required>
                    @error('password')
                        <span class="invalid-feedback" role="alert">
                            <strong>{{ $message }}</strong>
                        </span>
                    @enderror
                </div>
                <div class="form-group">
                <input id="password-confirm" type="password" class="form-control" name="password_confirmation" placeholder="Повторите пароль" autocomplete="new-password" required>
                </div>
                <button class="btn btn-primary btn-block" type="submit">Зарегистрироваться</button>
            </form>
            <a href="{{ route('login') }}">Уже зарегистрированы?</a>
        </div>
    </div>
</section>
@endsection