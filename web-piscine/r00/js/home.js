// Render items from DB
window.onload = function() {
  // let cart  = JSON parse DB

  if (cart) {
    let itemsHTML = cart.map(item => {
      return `<div id="item-${item.id}" class="item-row">
        <div class="image-container">
          <img
            class="item-image"
            src="${item.image}"
            alt="mars"
          />
        </div>
        <div class="details-container">
          <h3 class="item-title">${item.name} - $${item.price}</h3>
          <p class="item-description">
            &nbsp;${item.description}
          </p>
          <div class="button-row">
            <div class="counter-container">
              <button onclick="minusCount(${
                item.id
              })" class="small-button">-</button>
              <p id="counter-${item.id}" class="counter">1</p>
              <button onclick="plusCount(${
                item.id
              })" class="small-button">+</button>
            </div>
            <button onclick="addToCart(${item.id})" class="add-button">
              Add to cart
            </button>
          </div>
        </div>
      </div>`;
    });

    let storeItems = document.getElementById("store-items");
    storeItems.innerHTML = itemsHTML;
  }
};

function sortCruises() {}

function sortExcursions() {}

function sortSpas() {}

function minusCount(itemId) {
  let counter = document.getElementById(`counter-${itemId}`);
  let count = parseInt(counter.innerHTML);
  if (count > 1) {
    count--;
    counter.innerHTML = count;
  } else {
    counter.style.disabled = true;
  }
}

function plusCount(itemId) {
  let counter = document.getElementById(`counter-${itemId}`);
  let count = parseInt(counter.innerHTML);
  count++;
  counter.innerHTML = count;
}

function addToCart(itemId) {
  let counter = document.getElementById(`counter-${itemId}`);
  const count = parseInt(counter.innerHTML);
  let itemHTML = document.getElementById(`item-${itemId}`);
  let title = itemHTML.getElementsByClassName("item-title")[0].innerHTML;
  let image = itemHTML.getElementsByClassName("item-image")[0].src;
  let item = {
    id: itemId,
    name: title,
    number: count,
    image: image
  };
  // Change to array; Need to get previous and push to array
  let cart = JSON.parse(window.localStorage.getItem("cart"));
  if (!cart) {
    cart = [];
    cart.push(item);
  } else {
    //Prevent duplicate items
    cart.forEach((element, index, array) => {
      if (element.id == item.id) {
        array[index].number += item.number;
        item = null;
      }
    });
    if (item) {
      cart.push(item);
    }
  }
  window.localStorage.setItem("cart", JSON.stringify(cart));
}
