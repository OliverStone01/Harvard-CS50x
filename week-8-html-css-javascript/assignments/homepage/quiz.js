// Tracking score and checking users answer.

// Track score
let score = 0;

// Scratch
// Question 1:
document.querySelector('#dog').addEventListener('click', function(){
    scratchResult.innerHTML = ("Incorrect :(");
    scratchResult.style.color = 'Red';
});
document.querySelector('#fluffy').addEventListener('click', function(){
    scratchResult.innerHTML = ("Incorrect :(");
    scratchResult.style.color = 'Red';
});
document.querySelector('#cat').addEventListener('click', function(){
    scratchResult.innerHTML = ("Correct! :)");
    scratchResult.style.color = 'Green';
    score++;
});

// Question 2:
document.querySelector('#harvard').addEventListener('click', function(){
    scratchOneResult.innerHTML = ("Incorrect :(");
    scratchOneResult.style.color = 'Red';
});
document.querySelector('#cambridge').addEventListener('click', function(){
    scratchOneResult.innerHTML = ("Incorrect :(");
    scratchOneResult.style.color = 'Red';
});
document.querySelector('#mit').addEventListener('click', function(){
    scratchOneResult.innerHTML = ("Correct! :)");
    scratchOneResult.style.color = 'Green';
    score++;
});

// Question 3:
document.querySelector('#markup').addEventListener('click', function(){
    scratchTwoResult.innerHTML = ("Incorrect :(");
    scratchTwoResult.style.color = 'Red';
});
document.querySelector('#style').addEventListener('click', function(){
    scratchTwoResult.innerHTML = ("Incorrect :(");
    scratchTwoResult.style.color = 'Red';
});
document.querySelector('#visual').addEventListener('click', function(){
    scratchTwoResult.innerHTML = ("Correct! :)");
    scratchTwoResult.style.color = 'Green';
    score++;
});



// C
// Question 1
document.querySelector('#curlyBracket').addEventListener('click', function(){
    cOneResult.innerHTML = 'Incorrect :(';
    cOneResult.style.color = 'Red';
});
document.querySelector('#semiColen').addEventListener('click', function(){
    cOneResult.innerHTML = 'Correct! :)';
    cOneResult.style.color = 'Green';
    score++;
});
document.querySelector('#fullStop').addEventListener('click', function(){
    cOneResult.innerHTML = 'Incorrect :(';
    cOneResult.style.color = 'Red';
});

// Question 2
document.querySelector('#seventyTwo').addEventListener('click', function(){
    cTwoResult.innerHTML = 'Correct! :)';
    cTwoResult.style.color = 'Green';
    score++;
});
document.querySelector('#eightyFour').addEventListener('click', function(){
    cTwoResult.innerHTML = 'Incorrect :(';
    cTwoResult.style.color = 'Red';
});
document.querySelector('#nintySeven').addEventListener('click', function(){
    cTwoResult.innerHTML = 'Incorrect :(';
    cTwoResult.style.color = 'Red';
});

// Question 3:
document.querySelector('#else').addEventListener('click', function(){
    cThreeResult.innerHTML = ("Incorrect :(");
    cThreeResult.style.color = 'Red';
});
document.querySelector('#n').addEventListener('click', function(){
    cThreeResult.innerHTML = ("Incorrect :(");
    cThreeResult.style.color = 'Red';
});
document.querySelector('#print').addEventListener('click', function(){
    cThreeResult.innerHTML = ("Correct! :)");
    cThreeResult.style.color = 'Green';
    score++;
});



// Python
// Question 1
document.querySelector('#interpreter').addEventListener('click', function(){
    pythonResult.innerHTML = 'Correct! :)';
    pythonResult.style.color = 'Green';
    score++;
});
document.querySelector('#snake').addEventListener('click', function(){
    pythonResult.innerHTML = 'Incorrect :(';
    pythonResult.style.color = 'Red';
});
document.querySelector('#compiler').addEventListener('click', function(){
    pythonResult.innerHTML = 'Incorrect :(';
    pythonResult.style.color = 'Red';
});

// Question 2
document.querySelector('#true').addEventListener('click', function(){
    pythonOneResult.innerHTML = 'Correct! :)';
    pythonOneResult.style.color = 'Green';
    score++;
});
document.querySelector('#false').addEventListener('click', function(){
    pythonOneResult.innerHTML = 'Incorrect :(';
    pythonOneResult.style.color = 'Red';
});

// Question 3:
document.querySelector('#running').addEventListener('click', function(){
    pythonTwoResult.innerHTML = ("Incorrect :(");
    pythonTwoResult.style.color = 'Red';
});
document.querySelector('#hello').addEventListener('click', function(){
    pythonTwoResult.innerHTML = ("Incorrect :(");
    pythonTwoResult.style.color = 'Red';
});
document.querySelector('#py').addEventListener('click', function(){
    pythonTwoResult.innerHTML = ("Correct! :)");
    pythonTwoResult.style.color = 'Green';
    score++;
});



// SQL
// Question 1
document.querySelector('#web').addEventListener('click', function(){
    sqlOneResult.innerHTML = 'Incorrect :(';
    sqlOneResult.style.color = 'Red';
});
document.querySelector('#game').addEventListener('click', function(){
    sqlOneResult.innerHTML = 'Incorrect :(';
    sqlOneResult.style.color = 'Red';
});
document.querySelector('#databases').addEventListener('click', function(){
    sqlOneResult.innerHTML = 'Correct! :)';
    sqlOneResult.style.color = 'Green';
    score++;
});

// Question 2
document.querySelector('#squirrel').addEventListener('click', function(){
    sqlTwoResult.innerHTML = 'Incorrect :(';
    sqlTwoResult.style.color = 'Red';
});
document.querySelector('#silly').addEventListener('click', function(){
    sqltwoResult.innerHTML = 'Incorrect :(';
    sqlTwoResult.style.color = 'Red';
});
document.querySelector('#sequel').addEventListener('click', function(){
    sqlTwoResult.innerHTML = 'Correct! :)';
    sqlTwoResult.style.color = 'Green';
    score++;
});

// Question 3:
document.querySelector('#jpeg').addEventListener('click', function(){
    sqlThreeResult.innerHTML = ("Incorrect :(");
    sqlThreeResult.style.color = 'Red';
});
document.querySelector('#csv').addEventListener('click', function(){
    sqlThreeResult.innerHTML = ("Correct! :)");
    sqlThreeResult.style.color = 'Green';
    score++;
});
document.querySelector('#svg').addEventListener('click', function(){
    sqlThreeResult.innerHTML = ("Incorrect :(");
    sqlThreeResult.style.color = 'Red';
});


// HTML/CSS
// Question 1
document.querySelector('#hyperTextMakingLanguage').addEventListener('click', function(){
    htmlOneResult.innerHTML = 'Incorrect :(';
    htmlOneResult.style.color = 'Red';
});
document.querySelector('#hyperTextMarkupLanguage').addEventListener('click', function(){
    htmlOneResult.innerHTML = 'Correct! :)';
    htmlOneResult.style.color = 'Green';
    score++;
});

// Question 2
document.querySelector('#automation').addEventListener('click', function(){
    htmlTwoResult.innerHTML = 'Incorrect :(';
    htmlTwoResult.style.color = 'Red';
});
document.querySelector('#functionality').addEventListener('click', function(){
    htmlTwoResult.innerHTML = 'Incorrect :(';
    htmlTwoResult.style.color = 'Red';
});
document.querySelector('#styling').addEventListener('click', function(){
    htmlTwoResult.innerHTML = 'Correct! :)';
    htmlTwoResult.style.color = 'Green';
    score++;
});

// Question 3:
document.querySelector('#server').addEventListener('click', function(){
    htmlThreeResult.innerHTML = ("Correct! :)");
    htmlThreeResult.style.color = 'Green';
    score++;
});
document.querySelector('#html').addEventListener('click', function(){
    htmlThreeResult.innerHTML = ("Incorrect :(");
    htmlThreeResult.style.color = 'Red';
});
document.querySelector('#http').addEventListener('click', function(){
    htmlThreeResult.innerHTML = ("Incorrect :(");
    htmlThreeResult.style.color = 'Red';
});


// JavaScript
// Question 1
document.querySelector('#dynamic').addEventListener('click', function(){
    javaScriptOneResult.innerHTML = 'Correct! :)';
    javaScriptOneResult.style.color = 'Green';
    score++;
});
document.querySelector('#automatic').addEventListener('click', function(){
    javaScriptOneResult.innerHTML = 'Incorrect :(';
    javaScriptOneResult.style.color = 'Red';
});

// Question 2
document.querySelector('#nintyFive').addEventListener('click', function(){
    javaScriptTwoResult.innerHTML = 'Correct! :)';
    javaScriptTwoResult.style.color = 'Green';
    score++;
});
document.querySelector('#zeroOne').addEventListener('click', function(){
    javaScriptTwoResult.innerHTML = 'Incorrect :(';
    javaScriptTwoResult.style.color = 'Red';
});
document.querySelector('#nintyThree').addEventListener('click', function(){
    javaScriptTwoResult.innerHTML = 'Incorrect :(';
    javaScriptTwoResult.style.color = 'Red';
});

// Question 3:
document.querySelector('#head').addEventListener('click', function(){
    javaScriptThreeResult.innerHTML = ("Incorrect :(");
    javaScriptThreeResult.style.color = 'Red';
});
document.querySelector('#body').addEventListener('click', function(){
    javaScriptThreeResult.innerHTML = ("Incorrect :(");
    javaScriptThreeResult.style.color = 'Red';
});
document.querySelector('#linked').addEventListener('click', function(){
    javaScriptThreeResult.innerHTML = ("Incorrect :(");
    javaScriptThreeResult.style.color = 'Red';
});
document.querySelector('#allOfTheAbove').addEventListener('click', function(){
    javaScriptThreeResult.innerHTML = ("Correct! :)");
    javaScriptThreeResult.style.color = 'Green';
    score++;
});

document.querySelector('#getResult').addEventListener('click', function(){
    if (score >= 18)
    {
        resultModalLabel.innerHTML = 'You Smashed it!';
        resultModalBody.innerHTML = 'WOW 100% is very Impressive! congratulations';
        displayScore.innerHTML = (score + '/18');
    }
    else if (score > 10 && score < 18 )
    {
        resultModalLabel.innerHTML = 'Well Done!';
        resultModalBody.innerHTML = 'Thats a Very Good Score! Try again and see if you can get 100%!';
        displayScore.innerHTML = (score + '/18');
    }
    else
    {
        resultModalLabel.innerHTML = 'Better Luck Next time...';
        resultModalBody.innerHTML = 'Under 10... You can do better than that! give it another go!';
        displayScore.innerHTML = (score + '/18');
    }
});

document.querySelector('#tryAgain').addEventListener('click', function(){
    location.reload();
});
