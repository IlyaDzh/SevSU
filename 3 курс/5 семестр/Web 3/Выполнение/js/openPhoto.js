var photos = document.getElementsByClassName("img-elem");

for (let i = 0; i < photos.length; i++) {
    photos[i].addEventListener('click', () => {

        var titleImg = photos[i].children[1].innerHTML;
        var scrImg = photos[i].children[0].children[0].getAttribute("src");

        var bigImg = document.getElementById("testimg");
        bigImg.setAttribute("src", scrImg);

    });
}