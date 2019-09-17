var photos = document.getElementsByClassName("img-elem");
var testimg = document.getElementById("testimg");

var imgBg = document.getElementById("img-bg");
var popupMain = document.getElementById("popup-main");

for (let i = 0; i < photos.length; i++) {
    photos[i].addEventListener('click', () => {
        var scrImg = photos[i].children[0].children[0].getAttribute("src");
        testimg.setAttribute("src", scrImg);
        imgBg.classList.add("visible");
        popupMain.classList.add("visible");
    });
}

popupMain.addEventListener("click", () => {
    popupMain.classList.remove("visible");
    imgBg.classList.remove("visible");
});