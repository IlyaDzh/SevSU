var photos = document.getElementsByClassName("img-elem");

for (let i = 0; i < photos.length; i++) {
    $(photos[i]).click(() => {
        var scrImg = $(photos[i]).children("div").children("img").attr("src");
        $("#testimg").attr("src", scrImg);
        var title = $(photos[i]).children("h5").html();
        $("#control__title").html(title);
        $("#popup-main").addClass("visible");
        $("#img-bg").addClass("visible");
        $("#control").addClass("visible");

        $("#btn__right").click(() => {
            if (i == photos.length - 1)
                i = -1;
            scrImg = $(photos[++i]).children("div").children("img").attr("src");
            $("#testimg").fadeOut(100, function () {
                $(this).attr("src", scrImg);
                $(this).fadeIn(300);
            });
            title = $(photos[i]).children("h5").html();
            $("#control__title").html(title);
        });

        $("#btn__left").click(() => {
            if (i == 0)
                i = photos.length;
            scrImg = $(photos[--i]).children("div").children("img").attr("src");
            $("#testimg").fadeOut(100, function () {
                $(this).attr("src", scrImg);
                $(this).fadeIn(300);
            });
            title = $(photos[i]).children("h5").html();
            $("#control__title").html(title);
        });
    });
}

$("#popup-main").click(() => {
    $("#popup-main").removeClass("visible");
    $("#img-bg").removeClass("visible");
    $("#control").removeClass("visible");
})