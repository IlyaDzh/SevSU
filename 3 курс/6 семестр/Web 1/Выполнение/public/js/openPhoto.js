const photos = document.getElementsByClassName("img-elem");
const imgContainer = document.getElementById("img-container");

const imgBg = document.getElementById("img-bg");
const popupMain = document.getElementById("popup-main");

for (let i = 0; i < photos.length; i++) {
    photos[i].addEventListener("click", () => {
        const srcImg = photos[i].children[0].children[0].getAttribute("src");
        imgContainer.setAttribute("src", srcImg);
        imgBg.classList.add("visible");
        popupMain.classList.add("visible");
    });
}

popupMain.addEventListener("click", () => {
    popupMain.classList.remove("visible");
    imgBg.classList.remove("visible");
    imgContainer.setAttribute("src", "");
});
