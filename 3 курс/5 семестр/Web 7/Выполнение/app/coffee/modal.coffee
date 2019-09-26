modal = $('.cover, .modal, .modal__content')

$('.modal').click ->
    modal.fadeOut()
    return

$('.btn-danger').click ->
    modal.fadeIn()
    return