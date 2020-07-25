<?php

use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', function () {
    return view('welcome');
})->name("main");

Route::get('/about', function () {
    return view('about');
})->name("about");

Route::resource('blog', 'PostController')->names('posts');

Route::post('/comment/create', 'CommentController@create')->name('api.comment.create');

Route::patch('/post/update', 'PostController@update')->name('api.post.update');



Auth::routes();

Route::get('/home', function(){ 
    return redirect()->route('main'); 
})->name('home');

Route::get('/logout', '\App\Http\Controllers\Auth\LoginController@logout');