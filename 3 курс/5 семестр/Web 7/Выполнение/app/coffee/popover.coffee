$().ready ->
  DelayAp = 200
  DelayDis = 800
  ToolTipTimerAp = undefined
  ToolTipTimerDis = undefined
  $('.tooltip-input').hover(((e) ->
    $('.wy-tooltip').remove()
    clearTimeout ToolTipTimerDis
    title = $(@).attr('title')
    $(@).data('ToolTipText', title).removeAttr 'title'
    $('<div class="wy-tooltip wy-hide"></div>').text(title).appendTo 'body'
    ToolTipTimerAp = setTimeout(((e) ->
      $('.wy-tooltip').removeClass('wy-hide').fadeIn 'fast'
      return
    ), DelayAp)
    return
  ), ->
    clearTimeout ToolTipTimerAp
    $(@).attr 'title', $(@).data('ToolTipText')
    ToolTipTimerDis = setTimeout(((e) ->
      $('.wy-tooltip').remove()
      return
    ), DelayDis)
    return
  ).mouseenter (e) ->
    pLeft = undefined
    pTop = undefined
    offset = 10
    CursorX = e.pageX
    CursorY = e.pageY
    WindowWidth = $(window).width()
    WindowHeight = $(window).height()
    toolTip = $('.wy-tooltip')
    TTWidth = toolTip.width()
    TTHeight = toolTip.height()
    if CursorX - offset >= WindowWidth / 4 * 3
      pLeft = CursorX - TTWidth - offset
    else
      pLeft = CursorX + offset
    if CursorY - offset >= WindowHeight / 4 * 3
      pTop = CursorY - TTHeight - offset
    else
      pTop = CursorY + offset
    $('.wy-tooltip').css
      top: pTop
      left: pLeft
    return
  return