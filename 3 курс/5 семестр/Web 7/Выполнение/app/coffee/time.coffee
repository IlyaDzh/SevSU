setInterval (->
    time = new Date
    monthNames = [
        'января', 'февраля', 'марта', 'апреля', 'мая', 'июня', 'июля', 'августа', 'сентября', 'октября', 'ноября', 'декабря'
    ]
    $('#time').html "#{time.getDate()} #{monthNames[time.getMonth()]} #{time.getFullYear()} г. #{time.toLocaleTimeString()}"
    return
), 1000