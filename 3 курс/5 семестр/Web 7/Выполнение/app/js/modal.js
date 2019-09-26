var modal;

modal = $('.cover, .modal, .modal__content');

$('.modal').click(function() {
  modal.fadeOut();
});

$('.btn-danger').click(function() {
  modal.fadeIn();
});
