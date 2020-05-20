const timeContainer = document.getElementById("time");

function curTime() {
    setInterval(() => {
        const time = new Date();
        const monthNames = [
            "января",
            "февраля",
            "марта",
            "апреля",
            "мая",
            "июня",
            "июля",
            "августа",
            "сентября",
            "октября",
            "ноября",
            "декабря"
        ];
        timeContainer.innerHTML = `${time.getDate()} ${
            monthNames[time.getMonth()]
        } ${time.getFullYear()} г. ${time.toLocaleTimeString()}`;
    }, 1000);
}

curTime();
