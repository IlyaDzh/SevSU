@extends('layout.header')

@section('title', 'Блог')

@section('content')

<script src="{{ asset('js/sendComment.js') }}"></script>

<section class="content container">
    <h2 class="mb-4">Блог</h2>
    <div class='posts-block'>
        @foreach ($data as $item)
            <div class="card card-blog mb-4">
                <div class="row no-gutters">
                    <div class="col-md-4">
                        <img src="{{ $item->image ? $item->image : asset('img/not-found.png') }}" class="card-img">
                    </div>
                    <div class="col-md-8 d-flex flex-column">
                        <div class="card-body">
                            <h5 class="card-title">{{ $item->title }}</h5>
                            <p class="card-text">{{ $item->text }}</p>
                        </div>
                        <div class="card-footer">
                            <small class="text-muted">{{ $item->created_at }}</small>
                        </div>
                    </div>
                </div>
                <div class="card-comment">
                    <h6 class="card-comment__title">
                        Комментариев: 0
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

@endsection('content')