var photos = document.getElementsByClassName("img-elem");
var testimg = document.getElementById("testimg");
var controlTitle = document.getElementById("control__title");
var controlBlock = document.getElementById("control");

var btnLeft = document.getElementById("btn__left");
var btnRight = document.getElementById("btn__right");

var imgBg = document.getElementById("img-bg");
var popupMain = document.getElementById("popup-main");

for (let i = 0; i < photos.length; i++) {
    photos[i].addEventListener('click', () => {
        var scrImg = photos[i].children[0].children[0].getAttribute("src");
        var title = photos[i].children[1].innerHTML;
        testimg.setAttribute("src", scrImg);
        controlTitle.innerHTML = title;
        imgBg.classList.add("visible");
        popupMain.classList.add("visible");
        controlBlock.classList.add("visible");

        btnRight.addEventListener('click', () => {
            if (i == photos.length - 1) i = -1;
            scrImg = photos[++i].children[0].children[0].getAttribute("src");
            $("#testimg").fadeOut(100, function () {
                $(this).attr("src", scrImg);
                $(this).fadeIn(300);
            });
            title = photos[i].children[1].innerHTML;
            controlTitle.innerHTML = title;
        });

        btnLeft.addEventListener('click', () => {
            if (i == 0) i = photos.length;
            scrImg = photos[--i].children[0].children[0].getAttribute("src");
            $("#testimg").fadeOut(100, function () {
                $(this).attr("src", scrImg);
                $(this).fadeIn(300);
            });
            title = photos[i].children[1].innerHTML;
            controlTitle.innerHTML = title;
        });
    });
}

popupMain.addEventListener("click", () => {
    popupMain.classList.remove("visible");
    controlBlock.classList.remove("visible");
    imgBg.classList.remove("visible");
});