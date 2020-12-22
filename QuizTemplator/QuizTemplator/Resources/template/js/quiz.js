var currentPoints = 0;
var currentSlide = 1;
var maxPoints = 0;
var numSlides = 0; /*total number of slides*/
var percentProgress = currentPoints * 100 / maxPoints;
var mantext = new Array()
var results = new Array()

$(".quiz-slide").each(function (i) {

  maxPoints = maxPoints + $(this).data("quiz-point-value");
  numSlides = numSlides + 1;
  var slideID = "slide-" + numSlides;
  $(this).attr("id", slideID);
  $(".question-num", this).text(numSlides);

});
$("#slide-1").show();

console.log("Max points:", maxPoints);
console.log("current points:", currentPoints);

$("#score progress").attr("max", maxPoints);
$(".quiz #score .text .max-points,.quiz #final-score .max-points").text(maxPoints);


function updateScore(newPoints, currentPoints) {

  currentPoints = parseInt(currentPoints) + parseInt(newPoints);

  var percentProgress = currentPoints * 100 / maxPoints;
  var percentInPx = $("progress").width() * percentProgress / 100;
  percentInPx = percentInPx + "px";
  percentProgress = percentProgress + "%";
  $("#score .text .current-points").text(currentPoints);


  console.log(percentInPx);
  $(".quiz .pointer-container .pointer").css({
    '-webkit-transform': 'translateX(' + percentInPx + ')',
    '-moz-transform': 'translateX(' + percentInPx + ')',
    '-ms-transform': 'translateX(' + percentInPx + ')',
    '-o-transform': 'translateX(' + percentInPx + ')',
    'transform': 'translateX(' + percentInPx + ')'
  });

  $("#score progress").val(currentPoints);
  $(".progress-bar span").css("width", percentProgress).text(percentProgress);
  return currentPoints;


}

$("button .next-slide").click(function () {
  /*Multiple Choice buttons*/
  $(this).parents(".quiz-slide").addClass("answered");
  console.log("correct!");
  var newPoints = $(this).parents(".quiz-slide").attr("data-quiz-point-value");

  currentPoints = updateScore(newPoints, currentPoints);

});
$(".next-slide").click(function () {
  /*when progressing to next slide, hide completed slide and show new slide.*/
  $("#slide-" + currentSlide).hide();
  currentSlide = currentSlide + 1;

  $("#my_image").attr("src", "img/character/char" + currentSlide + ".png");
  mantext[1] = "Привет! Давайте подберём спектр необходимых вам услуг..."
  mantext[2] = "Интересно! Подскажите, какова система налогооблажения вашей компании?"
  mantext[3] = "И так, мы почти закончили... Какая у вас примерно выручка?"
  mantext[4] = "Отлично! Я уже начал собирать необходимую информацию, заполните форму!"
  $(".man-text").text(mantext[currentSlide]);


  if ($("#slide-" + currentSlide).hasClass("quiz-results")) {
    /*if slide is results slide update points and score*/
    $(".quiz #score").hide();
    $(".quiz #score").hide();
    $("#exampleModalLabel").hide();

    $("#resultInput").val(results[1] + " | " + results[2] + " | " + results[3]);
  }

  $("#slide-" + currentSlide).show();
  $('#progressPasha').attr('value', Number($('#progressPasha').attr('value')) + Number(5));

});

// Responsive Function
$(window).on('resize', function() {
  if ($(window).width() < 1200) {
    $(".man_speech").removeClass("col-md-3");
    $(".dynamite").removeClass('col-md-9').addClass('col-md-12');
  } else {
    $(".man_speech").addClass("col-md-3");
    $(".dynamite").removeClass('col-md-12').addClass('col-md-9');
  }
});

$( document ).ready(function() {
  if ($(window).width() < 1200) {
    $(".man_speech").removeClass("col-md-3");
    $(".dynamite").removeClass('col-md-9').addClass('col-md-12');
  } else {
    $(".man_speech").addClass("col-md-3");
    $(".dynamite").removeClass('col-md-12').addClass('col-md-9');
  }
});

// 1 slide
$("#choose-1").click(function () {
  $("#choose-1").removeClass('img-active');
  $("#choose-2").addClass('img-active');
  $("#choose-3").addClass('img-active');
  $("#choose-4").addClass('img-active');
  $('#next1').prop('disabled', false);
  results[1] = $("#choose-1").text();
});
$("#choose-2").click(function () {
  $("#choose-2").removeClass('img-active');
  $("#choose-1").addClass('img-active');
  $("#choose-3").addClass('img-active');
  $("#choose-4").addClass('img-active');
  $('#next1').prop('disabled', false);
  results[1] = $("#choose-2").text();
});
$("#choose-3").click(function () {
  $("#choose-3").removeClass('img-active');
  $("#choose-2").addClass('img-active');
  $("#choose-1").addClass('img-active');
  $("#choose-4").addClass('img-active');
  $('#next1').prop('disabled', false);
  results[1] = $("#choose-3").text();
});
$("#choose-4").click(function () {
  $("#choose-4").removeClass('img-active');
  $("#choose-2").addClass('img-active');
  $("#choose-3").addClass('img-active');
  $("#choose-1").addClass('img-active');
  $('#next1').prop('disabled', false);
  results[1] = $("#choose-4").text();
});

// 2 slide
$("#choose_2slide-1").click(function () {
  $("#choose_2slide-1").removeClass('img-active');
  $("#choose_2slide-2").addClass('img-active');
  $("#choose_2slide-3").addClass('img-active');
  $("#choose_2slide-4").addClass('img-active');
  $('#next2').prop('disabled', false);
  results[2] = $("#choose_2slide-1-1").text();
});
$("#choose_2slide-2").click(function () {
  $("#choose_2slide-2").removeClass('img-active');
  $("#choose_2slide-1").addClass('img-active');
  $("#choose_2slide-3").addClass('img-active');
  $("#choose_2slide-4").addClass('img-active');
  $('#next2').prop('disabled', false);
  results[2] = $("#choose_2slide-2").text();
});
$("#choose_2slide-3").click(function () {
  $("#choose_2slide-3").removeClass('img-active');
  $("#choose_2slide-2").addClass('img-active');
  $("#choose_2slide-1").addClass('img-active');
  $("#choose_2slide-4").addClass('img-active');
  $('#next2').prop('disabled', false);
  results[2] = $("#choose_2slide-3").text();
});
$("#choose_2slide-4").click(function () {
  $("#choose_2slide-4").removeClass('img-active');
  $("#choose_2slide-2").addClass('img-active');
  $("#choose_2slide-3").addClass('img-active');
  $("#choose_2slide-1").addClass('img-active');
  $('#next2').prop('disabled', false);
  results[2] = $("#choose_2slide-4").text();
});

// 3 slide
$("#choose_3slide-1").click(function () {
  $("#choose_3slide-1").removeClass('img-active');
  $("#choose_3slide-2").addClass('img-active');
  $("#choose_3slide-3").addClass('img-active');
  $("#choose_3slide-4").addClass('img-active');
  $('#next3').prop('disabled', false);
  results[3] = $("#choose_3slide-1").text();
});
$("#choose_3slide-2").click(function () {
  $("#choose_3slide-2").removeClass('img-active');
  $("#choose_3slide-1").addClass('img-active');
  $("#choose_3slide-3").addClass('img-active');
  $("#choose_3slide-4").addClass('img-active');
  $('#next3').prop('disabled', false);
  results[3] = $("#choose_3slide-2").text();
});
$("#choose_3slide-3").click(function () {
  $("#choose_3slide-3").removeClass('img-active');
  $("#choose_3slide-2").addClass('img-active');
  $("#choose_3slide-1").addClass('img-active');
  $("#choose_3slide-4").addClass('img-active');
  $('#next3').prop('disabled', false);
  results[3] = $("#choose_3slide-3").text();
});
$("#choose_3slide-4").click(function () {
  $("#choose_3slide-4").removeClass('img-active');
  $("#choose_3slide-2").addClass('img-active');
  $("#choose_3slide-3").addClass('img-active');
  $("#choose_3slide-1").addClass('img-active');
  $('#next3').prop('disabled', false);
  results[3] = $("#choose_3slide-4").text();
});