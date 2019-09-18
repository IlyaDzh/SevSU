var modal = $('.cover, .modal, .modal__content');

$('.modal').click(()=> {
    modal.fadeOut();
});

$('.btn-danger').click(() => {
    modal.fadeIn();
});