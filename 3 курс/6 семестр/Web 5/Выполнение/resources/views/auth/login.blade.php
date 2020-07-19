@extends('layout.header')

@section('content')
<section class="content container">
    <div class="row justify-content-center">
        <div class="col-lg-4 text-center">
            <h3 class="mb-4">Вход</h3>
            <form method="POST" action="{{ route('login') }}" class="mb-4">
                @csrf

                <div class="form-group">
                    <input type="email" class="form-control @error('email') is-invalid @enderror" name="email" value="{{ old('email') }}" placeholder="E-mail" autocomplete="email" required autofocus>
                    @error('email')
                        <span class="invalid-feedback" role="alert">
                            <strong>{{ $message }}</strong>
                        </span>
                    @enderror                
                </div>

                <div class="form-group">
                    <input type="password" class="form-control @error('password') is-invalid @enderror" name="password" placeholder="Пароль" autocomplete="current-password" required>
                    @error('password')
                        <span class="invalid-feedback" role="alert">
                            <strong>{{ $message }}</strong>
                        </span>
                    @enderror                
                </div>

                <button class="btn btn-primary btn-block" type="submit">Войти</button>
            </form>
            <a href="{{ route('register') }}">Зарегистрироваться</a>
        </div>
    </div>
</section>
@endsection