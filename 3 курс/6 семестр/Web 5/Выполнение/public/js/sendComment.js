function send(id) {
    const input = document.querySelector(`.form-control[data-id='${id}']`);
    const token = document
        .querySelector('meta[name="csrf-token"]')
        .getAttribute("content");

    if (input.value === "") return;

    const request = new Request("/comment/create", {
        method: "POST",
        body: JSON.stringify({
            post_id: id,
            comment: input.value
        }),
        headers: new Headers({
            "Content-Type": "application/json",
            "X-CSRF-TOKEN": token
        })
    });

    fetch(request)
        .then(response => response.json())
        .then(data => {
            const input = document.querySelector(
                `.form-control[data-id='${data.post_id}']`
            );

            const numberComments = input.parentNode.parentNode.parentNode.querySelector(
                ".card-comment__title"
            );
            numberComments.innerHTML =
                "Комментариев: " + parseInt(numberComments.innerHTML) + 1;

            const commentContainer = input.parentNode.parentNode.parentNode.querySelector(
                ".card-comment__container"
            );
            commentContainer.insertAdjacentHTML(
                "beforeend",
                `<div class="comment-item">
                    <div class="d-flex">
                        <div class="comment-item__name">${data.fullname},</div>
                        <div class="comment-item__date">${data.created_at}</div>
                    </div>
                    <div class="comment-item__text">${data.comment}</div>
                </div>`
            );

            input.value = "";
        });
}
