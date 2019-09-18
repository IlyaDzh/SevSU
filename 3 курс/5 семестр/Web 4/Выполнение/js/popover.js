$().ready(function () {
    var DelayAp = 200;
    var DelayDis = 400;
    var ToolTipTimerAp, ToolTipTimerDis;
    $('.tooltip-input').hover(function (e) {
        $('.wy-tooltip').remove();
        clearTimeout(ToolTipTimerDis);
        var title = $(this).attr('title');
        $(this).data('ToolTipText', title).removeAttr('title');
        $('<div class="wy-tooltip wy-hide"></div>').text(title).appendTo('body');
        ToolTipTimerAp = setTimeout(function (e) {
            $('.wy-tooltip').removeClass('wy-hide').fadeIn('fast');
        }, DelayAp);
    }, function () {
        clearTimeout(ToolTipTimerAp);
        $(this).attr('title', $(this).data('ToolTipText'));
        ToolTipTimerDis = setTimeout(function (e) {
            $('.wy-tooltip').remove();
        }, DelayDis);
    }).mousemove(function (e) {
        var pLeft;
        var pTop;
        var offset = 10;
        var CursorX = e.pageX;
        var CursorY = e.pageY;
        var WindowWidth = $(window).width();
        var WindowHeight = $(window).height();
        var toolTip = $('.wy-tooltip');
        var TTWidth = toolTip.width();
        var TTHeight = toolTip.height();
        if (CursorX - offset >= (WindowWidth / 4) * 3) {
            pLeft = CursorX - TTWidth - offset;
        } else {
            pLeft = CursorX + offset;
        }
        if (CursorY - offset >= (WindowHeight / 4) * 3) {
            pTop = CursorY - TTHeight - offset;
        } else {
            pTop = CursorY + offset;
        }
        $('.wy-tooltip').css({ top: pTop, left: pLeft })
    });
});