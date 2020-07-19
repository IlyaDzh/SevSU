<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Comment;
use Illuminate\Support\Facades\Auth;

class CommentController extends Controller
{
    public function create(Request $request) {
        $date = date('m/d/Y h:i:s', time());

        $item = new Comment(); 
        $item->fullname = Auth::user()->name;
        $item->created_at = $date;
        $item->updated_at = $date;
        $item->fill($request->input()); 

        $item->save();
        
        return response()->json($item);
    }
}
