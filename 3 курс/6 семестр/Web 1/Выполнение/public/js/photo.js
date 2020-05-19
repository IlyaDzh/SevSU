const photosArray = [
    [
        { img: "animal-4454043_1280.jpg", title: "Птица" },
        { img: "norway-4453338_1280.jpg", title: "Город" },
        { img: "plantation-4452538_1280.jpg", title: "Деревья" },
        { img: "stingray-4392776_1280.jpg", title: "Рыба" },
        { img: "snail-4428838_1280.jpg", title: "Улитка" },
        { img: "ara-3601194_640.jpg", title: "Попугай" }
    ],
    [
        { img: "owl-4461236_640.jpg", title: "Сова" },
        { img: "desert-1916882_1280.jpg", title: "Пустыня" },
        { img: "pets-4415649_1280.jpg", title: "Собака" },
        { img: "port-4401223_1280.jpg", title: "Птица" },
        { img: "tree-4450514_1280.jpg", title: "Деревья" },
        { img: "twilight-4453762_1280.jpg", title: "Горы" }
    ],
    [
        { img: "hot-air-balloons-4381674_1280.jpg", title: "Воздушные шары" },
        { img: "pine-cones-4454654_1280.jpg", title: "Шишки" },
        { img: "african-grey-parrot-4424746_1280.jpg", title: "Птица" },
        { img: "landscape-4449408_1280.jpg", title: "Озеро" },
        { img: "squirrel-4425612_1280.jpg", title: "Белка" },
        { img: "sea-2361247_640.jpg", title: "Черепаха" }
    ]
];

photosArray.forEach(element => {
    document.writeln("<div class='col-md-4'>");
    element.forEach(elementLast => {
        document.writeln(
            `<div class='img-elem'>
                <div class='img-wrapper rounded'>
                    <img class='img-fluid rounded inner-img' src='public/img/photo/${elementLast.img}' title='${elementLast.title}'>
                </div>
                <h5 class='photo__subtitle'>${elementLast.title}</h5>
            </div>`
        );
    });
    document.writeln("</div>");
});
