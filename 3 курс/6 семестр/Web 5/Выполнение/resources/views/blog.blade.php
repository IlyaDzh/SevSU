@extends('layout.header')

@section('title', 'Блог')

@section('content')

<script src="{{ 'js/sendComment.js' }}"></script>

<section class="content container">
    @if (Auth::user() && Auth::user()->isAdmin)
        <form action="{{ route('posts.store') }}" method="POST" enctype="multipart/form-data" class="mb-4">
            @csrf
            <div class="form-group">
                <input type="text" class="form-control tooltip-input" value="{{ old('title') }}" name="title" placeholder="Тема сообщения" autocomplete="off">
            </div>
            <div class="form-group">
                <div class="custom-file">
                    <input type="file" name="image" accept=".png, .jpeg, .jpg" class="form-control" id="uploadInput" aria-describedby="uploadInputBtn">
                    <label class="custom-file-label" for="uploadInput">Загрузите изображение</label>
                </div>
            </div>
            <div class="form-group">
                <textarea class="form-control" name="text" rows="4" placeholder="Введите сообщение">{{ old('text') }}</textarea>
            </div>
            <button class="btn btn-primary" type="submit">Добавить</button>
        </form>

        @foreach ($errors->all() as $error)
            <div>{{ $error }}</div>
        @endforeach
    @endif

    <h2 class="mb-4 mt-4">Блог</h2>
    <div class='posts-block'>
        @if ($data->isEmpty())
            <h6>Нет постов</h6>
        @endif

        @foreach ($data as $item)
            <div class="card card-blog mb-4">
                <div class="row no-gutters">
                    <div class="col-md-4">
                        <img src="{{ $item->image ? $item->image : 'img/not-found.png' }}" class="card-img">
                    </div>
                    <div class="col-md-8 d-flex flex-column">
                        <div class="card-body">
                            <h5 class="card-title">{{ $item->title }}</h5>
                            <p class="card-text">{{ $item->text }}</p>
                            @if (Auth::user() && Auth::user()->isAdmin)
                                <button 
                                    class="btn edit-btn" 
                                    type="button" 
                                    data-id="{{ $item->id }}" 
                                    data-title="{{ $item->title }}" 
                                    data-text="{{ $item->text }}" 
                                >
                                    <img src="{{ 'img/edit.svg' }}"/>
                                </button>
                                <form action="{{ route('posts.destroy', $item->id) }}" method="POST">
                                    @csrf
                                    @METHOD("DELETE")
                                    <button class="btn delete-btn" type="submit">
                                        <img src="{{ 'img/trash.svg' }}"/>
                                    </button>
                                </form>
                            @endif
                        </div>
                        <div class="card-footer">
                            <small class="text-muted">{{ $item->created_at }}</small>
                        </div>
                    </div>
                </div>
                <div class="card-comment">
                    <h6 class="card-comment__title">
                        Комментариев: {{ count($item->comments) }}
                    </h6>
                    <div class="card-comment__container">
                        @foreach ($item->comments as $comment)
                            <div class="comment-item">
                                <div class="d-flex">
                                    <div class="comment-item__name">{{ $comment->fullname }},</div>
                                    <div class="comment-item__date">{{ $comment->created_at }}</div>
                                </div>
                                <div class="comment-item__text">{{ $comment->comment }}</div>
                            </div>
                        @endforeach
                    </div>
                    @if (auth()->check())
                        <div class="card-comment__add">
                            <div class="input-group">
                                <input data-id="{{ $item->id }}" type="text" class="form-control" name="comment" placeholder="Введите ваш комментарий" aria-describedby="send-btn" autocomplete="off">
                                <div class="input-group-append">
                                    <button 
                                        class="btn btn-outline-secondary" 
                                        type="button" 
                                        id="send-btn"
                                        onClick="send({{ $item->id }})"
                                    >
                                        Отправить
                                    </button>
                                </div>
                            </div>
                        </div>
                    @endif
                </div>
            </div>
        @endforeach
    </div>

    <div class="d-flex justify-content-center">
        @if ($data->total() > $data->count())
            {{ $data->links() }}
        @endif
    </div>
</section>

<div class="modal hidden">
    <div class="container">
        <div class="body">
            <h4 class="text-center mb-4">Редактирование</h4>
            <form>
                <div class="form-group">
                    <input id="editTitle" type="text" class="form-control tooltip-input" placeholder="Тема сообщения" autocomplete="off">
                </div>
                <div class="form-group">
                    <textarea id="editMessage" class="form-control" rows="4" placeholder="Введите сообщение"></textarea>
                </div>
                <button id="saveBtn" class="btn btn-primary w-100" type="button">Сохранить</button>
            </form>
        </div>
    </div>
</div>

<script>
    const inputFile = document.getElementById("uploadInput");
    const inputLabel = document.getElementsByClassName("custom-file-label")[0];
    inputFile.addEventListener("change", e => {
        inputLabel.innerHTML = e.target.files[0].name;
    });
</script>
<script src="{{ 'js/editBlog.js' }}"></script>

@endsection('content')
