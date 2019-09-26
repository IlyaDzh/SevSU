$().ready(function() {
  var DelayAp, DelayDis, ToolTipTimerAp, ToolTipTimerDis;
  DelayAp = 200;
  DelayDis = 800;
  ToolTipTimerAp = void 0;
  ToolTipTimerDis = void 0;
  $('.tooltip-input').hover((function(e) {
    var title;
    $('.wy-tooltip').remove();
    clearTimeout(ToolTipTimerDis);
    title = $(this).attr('title');
    $(this).data('ToolTipText', title).removeAttr('title');
    $('<div class="wy-tooltip wy-hide"></div>').text(title).appendTo('body');
    ToolTipTimerAp = setTimeout((function(e) {
      $('.wy-tooltip').removeClass('wy-hide').fadeIn('fast');
    }), DelayAp);
  }), function() {
    clearTimeout(ToolTipTimerAp);
    $(this).attr('title', $(this).data('ToolTipText'));
    ToolTipTimerDis = setTimeout((function(e) {
      $('.wy-tooltip').remove();
    }), DelayDis);
  }).mouseenter(function(e) {
    var CursorX, CursorY, TTHeight, TTWidth, WindowHeight, WindowWidth, offset, pLeft, pTop, toolTip;
    pLeft = void 0;
    pTop = void 0;
    offset = 10;
    CursorX = e.pageX;
    CursorY = e.pageY;
    WindowWidth = $(window).width();
    WindowHeight = $(window).height();
    toolTip = $('.wy-tooltip');
    TTWidth = toolTip.width();
    TTHeight = toolTip.height();
    if (CursorX - offset >= WindowWidth / 4 * 3) {
      pLeft = CursorX - TTWidth - offset;
    } else {
      pLeft = CursorX + offset;
    }
    if (CursorY - offset >= WindowHeight / 4 * 3) {
      pTop = CursorY - TTHeight - offset;
    } else {
      pTop = CursorY + offset;
    }
    $('.wy-tooltip').css({
      top: pTop,
      left: pLeft
    });
  });
});
