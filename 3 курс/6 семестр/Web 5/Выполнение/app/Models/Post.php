<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Post extends Model
{
    protected $fillable = [ 
        'title', 
        'image',
        'text'
    ];
    
    public function comments() { 
        return $this->hasMany(Comment::class); 
    }
}
