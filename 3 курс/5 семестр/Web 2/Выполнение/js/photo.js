var photos = [
    [
        { img: "img/photo/animal-4454043_1280.jpg", title: "Птица" },
        { img: "img/photo/norway-4453338_1280.jpg", title: "Город" },
        { img: "img/photo/plantation-4452538_1280.jpg", title: "Деревья" },
        { img: "img/photo/stingray-4392776_1280.jpg", title: "Рыба" },
        { img: "img/photo/snail-4428838_1280.jpg", title: "Улитка" },
        { img: "img/photo/ara-3601194_640.jpg", title: "Попугай" }
    ],
    [
        { img: "img/photo/owl-4461236_640.jpg", title: "Сова" },
        { img: "img/photo/desert-1916882_1280.jpg", title: "Пустыня" },
        { img: "img/photo/pets-4415649_1280.jpg", title: "Собака" },
        { img: "img/photo/port-4401223_1280.jpg", title: "Птица" },
        { img: "img/photo/tree-4450514_1280.jpg", title: "Деревья" },
        { img: "img/photo/twilight-4453762_1280.jpg", title: "Горы" }
    ],
    [
        { img: "img/photo/hot-air-balloons-4381674_1280.jpg", title: "Воздушные шары" },
        { img: "img/photo/pine-cones-4454654_1280.jpg", title: "Шишки" },
        { img: "img/photo/african-grey-parrot-4424746_1280.jpg", title: "Птица" },
        { img: "img/photo/landscape-4449408_1280.jpg", title: "Озеро" },
        { img: "img/photo/squirrel-4425612_1280.jpg", title: "Белка" },
        { img: "img/photo/sea-2361247_640.jpg", title: "Черепаха" }
    ]
];

photos.forEach(element => {
    document.writeln("<div class='col-md-4'>");
    element.forEach(elementLast => {
        document.writeln(`<div class='img-elem'><div class='img-wrapper rounded'><img class='img-fluid rounded inner-img' src='${elementLast.img}' title='${elementLast.title}'></div><h5 class='photo__subtitle'>${elementLast.title}</h5></div>`);
    });
    document.writeln("</div>");
})