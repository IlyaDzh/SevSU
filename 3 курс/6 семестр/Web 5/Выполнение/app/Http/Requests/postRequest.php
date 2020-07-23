<?php

namespace App\Http\Requests;

use Illuminate\Foundation\Http\FormRequest;

class postRequest extends FormRequest
{
    /**
     * Determine if the user is authorized to make this request.
     *
     * @return bool
     */
    public function authorize()
    {
        return true;
    }

    /**
     * Get the validation rules that apply to the request.
     *
     * @return array
     */
    public function rules()
    {
        return [
            'title' => 'required|min:3|max:200',
            'text' => 'required|min:3|max:5000'
        ];
    }

    public function messages()
    {
        return [
            'title.required' => 'Поле Тема обязательно!',
            'title.min' => 'Поле Тема должен содержать не менее :min символов!',
            'title.max' => 'Поле Тема должен содержать не более :max символов!',
            'text.required' => 'Поле Сообщение обязательно!',
            'text.min' => 'Поле Сообщение должно содержать не менее :min символов!',
            'text.max' => 'Поле Сообщение должно содержать не более :max символов!',
        ];
    }
}
