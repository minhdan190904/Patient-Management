var h1Element = document.getElementById('numberRoom');
if (h1Element) {
  var pageTitle = h1Element.textContent;
  var roomNumberMatch = pageTitle.match(/\d+/);
  if (roomNumberMatch) {
    var roomNumber = roomNumberMatch[0];
    var localStorageKey = "patients" + roomNumber;
  }
}