function curTime() {
    setInterval(() => {
        let time = new Date();
        var monthNames = [
            "января", "февраля", "марта",
            "апреля", "мая", "июня", "июля",
            "августа", "сентября", "октября",
            "ноября", "декабря"
        ];
        document.getElementById('time').innerHTML = `${time.getDate()} ${monthNames[time.getMonth()]} ${time.getFullYear()}г. ${time.toLocaleTimeString()}`;
    }, 1000)
}

curTime();