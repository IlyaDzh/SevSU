$().ready(function () {
    const DelayAp = 200;
    const DelayDis = 800;
    let ToolTipTimerAp, ToolTipTimerDis;
    $(".tooltip-input")
        .hover(
            function (e) {
                $(".wy-tooltip").remove();
                clearTimeout(ToolTipTimerDis);
                let title = $(this).attr("title");
                $(this).data("ToolTipText", title).removeAttr("title");
                $('<div class="wy-tooltip wy-hide"></div>')
                    .text(title)
                    .appendTo("body");
                ToolTipTimerAp = setTimeout(function (e) {
                    $(".wy-tooltip").removeClass("wy-hide").fadeIn("fast");
                }, DelayAp);
            },
            function () {
                clearTimeout(ToolTipTimerAp);
                $(this).attr("title", $(this).data("ToolTipText"));
                ToolTipTimerDis = setTimeout(function (e) {
                    $(".wy-tooltip").remove();
                }, DelayDis);
            }
        )
        .mouseenter(function (e) {
            let pLeft, pTop;
            const offset = 10;
            const CursorX = e.pageX;
            const CursorY = e.pageY;
            const WindowWidth = $(window).width();
            const WindowHeight = $(window).height();
            const toolTip = $(".wy-tooltip");
            const TTWidth = toolTip.width();
            const TTHeight = toolTip.height();
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
            $(".wy-tooltip").css({ top: pTop, left: pLeft });
        });
});
