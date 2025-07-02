## 📚 CS50 week 8 - HTML, CSS, JavaScript

### Summary
- Summary here

---

## HTML & CSS
HTML = Hypertext Markup language
CSS = Cascading Style Sheets

Let’s talk about what makes up the internet (World Wide Web). The internet is like plumbing that connects data from point A to B. It’s a load of computers linked together wirelessly or wired. This is what makes up our internet, a set of computers working together to intercommunicate.

When the first servers were introduced, making the ARPANET. To get data from point A to point B, you need to route the information. The first thing we need to look at then are:

### Routers
Routers are computers whose job it is to route information. They may look a little different and be in large data centres. The main difference is the software they run. The job of these routers is when they receive an email or a text. They decide which way to send the information. 

So how do routers figure out which way to send information? Well, the language they use is `TCP/IP`. This is technically two protocols together. 

-----

### IP

`IP` = Internet Protocol

This is the language, more of a protocol to be proper. That computers speak when sending information between each other.

A protocol is a set of conventions. For instance, when you greet someone, you would hold your hand out to shake their hand. The other person would reach their hand out and shake it as this is human protocol. So thats exactly what TCP/IP is. Its less of a language and more of a convention. IP is specifically focused on addressing servers in the world.

Every computer in the world has its own IP address. Which is a unique identifier that is typically in this format:
```
#.#.#.#
```
Where each # is a simple integer ranging from 0 to 255. That means you have 4 values that could be 0 to 255. This means that an IP address is 32 bits (4 bytes). What that means is you can have a maximum of around 4 billion IP addresses. This is known as IP type 4.

But there are lots of people in the world, and there are many people with multiple devices so it wont take long to use up those 4 billion addresses. So the world is now starting to use IP type 6.

For now, though, we will concentrate on type 4.

Here is some ASCII art showing the diagram from the RFC (Request For Comment) which defines how IP is supposed to work.

<img src=>

When sending messages, we will use an envelope as our container for our message. What you need to do is write the destination address and the source address (your address).

Let’s say Brenda has a message she wants to send to Brian. What the software would do is put the address she wants the message to go to Brian’s address. The router would then pass the envelope to the next router. The next router would look at the address and see which router it can pass it to next to get to the correct address. This will continue until the correct router is reached.

So let’s say that she wanted to send a photo of a cat. Well, you wouldn’t want to send such a large item in the envelope as it won’t fit. So what the computer does is `fragment` the information and place each chunk into its own envelope addressed to the same location. The only issue with this is you don’t know what order the data will arrive in.

-----

### TCP

TCP has a few jobs. But one of them is to ensure we acknowledge how many envelopes were sent. So, on the envelope now, not only are we going to mark the address, but we are now going to add 1 of 4, for example.

What this allows is confirmation of delivery, as Brian’s computer can confirm it has received all the data it needs to make up the message. This also allows Brian’s computer to tell Brenda that the message has been received.

The other thing that TCP does is define the types of data using ports.

A port Is a unique numeric identifier for a specific internet service. For example:

- `80` = HTTP (World wide web traffic)
- `443` = HTTPS (Secure versions of HTTP)
- `25` = Email
- `53` = DNS
There are many more.

What Brenda can now do is, let’s say, Brian is actually a website. What she can do is add the port to the end of the address like such:
```
1.2.3.4:80
```
And now when Brian receives the envelope, it knows it’s not email, it’s for the website.

So what does TCPIP do? Well, it allows us to address computers on the internet and to guarantee delivery by using sequence numbers and to make sure it goes to the right place using port numbers.

-----

### DNS

As users, don’t use IP addresses with port numbers when we want to go to websites. Well, not only are there router servers, there are also DNS servers (Domain Name Systems); these typically are hosted on your internet provider’s network. What it does is translate domain names into IP addresses. So you can type google.com and the server will do the IP address writing for you.

The server has in its memory a two-column dictionary.
```
Fully Qualified Domain Name | IP Address
- - - - - - - - - - - - - - | - - - - - -
                            |
```
Google.com would be in the left hand side and the IP address of google on the right hand side.

The DNS is designed to be hierarchical, which means that your internet provider’s DNS server can translate many domain names to IP addresses, especially if they are popular, as it saves popular searches to be able to offer quicker responses. If you visit a random site that’s not very popular, then your internet provider’s server will have to ask another DNS server for the address recursively.

Around the world, there are `Root Servers` which store all of the `.com` sites and all the other types like `.org` and `.gov`, and if they don’t know the answer, they know which server to ask to get the right information.

If you buy a domain, you are paying for someone to add an entry to their DNS server, or someone else’s DNS server, which then associates that domain with a specific IP address.

The whole process is very recursive because if you are using your phone, for example, your phone will remember the popular IP addresses in its cache. But if the answer is not there, then it will ask the DNS server; then if that DNS server doesn’t know, it will ask the next server; then the next, and then maybe one of the root servers. But eventually, as long as it exists. One of the servers will return the IP address.

You can break a website depending on how the DNS Expiration is set up. If you set the Expiration to 1 minute, for example, then it will cache the IP address of that site for 1 minute without looking for it again. But if you set the expiration to 1 year and you then update that IP address, the cache will be incorrect and would cause lots of issues.

The expiration acts like a refresh to make sure that the IP address is still correct instead of keeping the same data stored in the cache.

-----

### DHCP

`DHCP` = Dynamic Host Configuration Protocol.

The purpose of this software is to give your computer an IP address every time you boot up. This wasn’t always the case; in the old days, your internet provider would come to your house and use a sheet to configure your device to a set IP address. 

But now we do this using DHCP. Every time you boot your device (if the IP address has expired), it will send a message to your local network asking what IP address it should use. Then it will get a response saying, “Use this IP address.”

DHCP will also give your computer an address to the DNS server to use. It will also tell you what your default gateway is.

-----

### HTTP and others

`HTTP` is how web browsers and web servers communicate. It is related to HTTPS which is a encrypted version of HTTP.

Your browser will automatically add the https nowadays as a prefix if you forget to add them. For example, if you type google.com, it will automatically add https:// to the front.

`URL` = Uniform Resource Locators
```
https://www.example.com/
```
The trailing / at the end tells the web browser that you want to see the default of that website (the homepage, if you will).

Another thing you might see is after the trailing / you will see a directory to other parts of the site.
```
https://www.example.com/folder/
```

`/file.html` - this would go to a file called file.html in the website.

Sometimes you might get nested files inside of a directory. Like this:
```
https://www.example.com/folder/file.html
```

When you are talking about a domain name, typically you are talking about the `example.com` part of the URL.

The rest of the URL is actually called a `Host name`. This is the name of a specific server (or a group of servers )(www).

Lastly, the last part of jargon is the end of the URL (.com). This is known as:

### TLD

`TLD` = Top Level Domain.

This indicates what type of domain it is. In the US for example:
```
.com = commercial
.gov = government
.org = organisation
```
There are so many TLDs out there. Most countries have their own which are usually 2 characters long. For example:
```
.us
.uk
```

So the HTTPS dictates the protocol that the browser uses when requesting a webpage. So what does this protocol do? Well, it’s a lot like a handshake. The browser holds out its hand with the GET request to the server, hoping that the server will hold out its hand and return with data. 

`GET` = Get a specific webpage.
`POST` = send information somewhere else.

If we go back to thinking about the message being sent from browser to server as an envelope. The message might look like this:
```
GET / HTTP/2
Host: www.harvard.edu
```
And the return data from the server is a response:
```
HTTP/2 200
Content-Type: text/html
```

-----

### Headers

Let's use some code for this. In the terminal we will use `curl`.

`curl` = Connect URL

```
$ curl -I https://www.harvard.edu/
```
Output:
```
HTTP/2 200
Server: nginx
Date: Wed, 23 Oct 2024 17:56:05 GMT
Content-type: text/html; charset=UTF-8
Vary: Accept-Encoding
X-hacker: If you’re reading this, you should visit wpvip.com/careers and apply to join the fun, menti on this header.
Host-header: a9130478a60e5f9135f765b23f26593b
Link: <https://www.harvard.edu/>; rel=shortlink
X-rq: dca5 96 184 443
Accept-ranges: bytes
X-cache: HIT
Cache-control: max-age=300, must-revalidate
```

Let's break these headers down.

The `-I` in the request means just show me the headers, not the actual data.

`HTTP/2` Is the version of HTTP that the browser and server are communicating in.

`200` = This Is the status code for OK

Here are some other status codes you will see:
- `301` = permanently moved.
- `404` = file not found
- `302` = found
- `304` = Not Modified
- `307` = Temporary Redirect
- `401` = Unauthorised
- `403` = Forbidden
- `418` = I’m a teapot (April fouls joke)
- `500` = Internal Server Error
- `503` = Service Unavailable

-----

## HTML

`Tags` = < >
Attributes 

Here is an example of HTML code:
```
<!DOCTYPE html>

<html lang=“en”>
    <head>
        <title>
            hello, title
        </title>
    </head>
    <body>
        hello, body
    </body>
</html>
```
`HTTP-server` = Starts your own webserver on port 8080.

When you have started your server, you can add web pages by doing `code webpage.html` in the terminal window.

The title in HTML is the text in the tab section, and the body is the webpage itself. 

`<!DOCTYPE html>` = This declares to the browser that it is about to receive a webpage written in HTML.

`<html lang=“en”>` = This is the beginning of an HTML element called HTML and indicates what human language is going to be used.

`<head>` = This is the top of the page (including the tab).

`<p> </P` = Inside the body, you can add a paragraph tag. This will add spaces between paragraphs.

`<h1> text </h1>` = This adds a header to the page inside the body area.

`H1` is the biggest header and bold
`H2` is not as big but still bold
`H3` is smaller but still bold

`<ul> </ul>` = unordered list - this will add bullet points.

Inside the `ul` tag, you can then use:

`<li> </li>` = List item.

For example:
```
<body>
    <ul>
        <li>foo</li>
        <li>bar</li>
        <li>baz</li>
    </ul>
</body>
```

`<ol> </ol>` = Ordered list which starts with a number.

`<!-- comment -->` This is a comment.

For a table, you need to do the following:
`tr` is Table Row
`td` is Table Data 
```
<body>
    <table>
        <tr>
            <td>1</td>
            <td>2</td>
            <td>3</td>
        </tr
        <tr>
            <td>4</td>
            <td>5</td>
            <td>6</td>
        </tr>
        <tr>
            <td>7</td>
            <td>8</td>
            <td>9</td>
        </tr>
        <tr>
            <td>*</td>
            <td>0</td>
            <td>#</td>
        </tr>
    </table>
</body>
```

This would display on the browser:
```
1 2 3
4 5 6
7 8 9
- 0 #
```

This is how you add images to websites:
```
<body>
    <img src=“bridge.png”>
</body>
```
The IMG part declares that an image is being placed. SRC is the source of the image. You will also notice that you don't need a closing tag for images.

If you ever see a broken image, whether that’s from misspelling or anything else. You will get an image icon with a crack. What you can do is add an alternative text to display and to also help with people who use screen readers. 
```
<body>
    <img alt=“Harvard University” src=“bridge.png”>
</body>
```

For a video you need to use the video tag:
```
<body>
    <video controls muted>
        <source src=“video.mp4” type=“video/mp4”>
    </video>
</body>
```
The controls tag gives the user a play and pause menu, and the muted mutes the video.

Here is how you make clickable links:
```
<body>
    Visit <a href=“image.html”>Harvard</a>
</body>
```
The `<a>` tag is an anchor tag.
`Href` = hyper reference.

If you are going to link to an actual URL, you need to include the entire link like such:
```
<body>
    Visit <a href=“https://www.harvard.edu/">Harvard </a>
</body>
```

We can also except an input. Lets use google as the example here. What we need to look at is `key value pairs`.

`Key = value`

To tell the server you are passing it a query, you use `?`:
```
https://www.google.com/search?q=cats
```
Let’s look at how you would make an input and search button:
```
<body>
    <form action=“https://www.google.com/search" method=“get”>
        <input autocomplete=“off” autofocus name=“q” placeholder=“query” type=“search”>
        <input type=“submit” value=“Google Search”>
    </form>
</body>
```

Here is how you make a forme with a submit:
```
<body>
    <form>
        <input autocomplete=“off” autofocus name=“email” placeholder=“email” type=“email”>
        <button> Register </button>
    </form>
</body>
```

`regexes` = Regular Expression.

This allows you to check inputs:
- `.` = any single character (except line terminators)
- `*` = zero or more times
- `+` = one or more times
- `?`	=	0 or 1 time
- `{n}` = n occurrences
- `{n, m}` = at least n occurrences, at most m occurrences

- `[0123456789]` = any one of the enclosed characters
- `[0-9]` = any one of the range of characters
- `\d` = any digit
- `\D` = any character that is not a digit
= `\.` = give me a .

To place these in instead of using type email, for example. You need to use a pattern like such:
```
<body>
    <form>
        <input autocomplete=“off” autofocus name=“email” pattern=“.+@.+\.edu” placeholder=“Email”>
        <button> register </button>
    </form>
</body>
```
You can validate your own HTML code at: validator.w3.org

-----

## CSS

`CSS` = Cascading Style Sheets

This is used to style your HTML sites.

`Properties` = Set of key-value pairs

- Type Selector
- Class Selector
- ID Selector
- Attribute Selector

To tell your code you want to include some CSS can be done in two methods:

The first is `<style>` tags:
```
<!DOCTYPE html>

<html lang=“en”>
    <head>
        <style>
		
        </style>
    </head>
</html>
```
Or you can link a css file in with all the properties.
```
<html language=“en”>
    <head>
        <link href=“styles.css” rel=“stylesheet”>
    </head>
</html>
```
So how would you change font size? Well, you can do this:
```
<html lang”en”>

    <head>
        <title>home</title>
    </head>
    <body>
        <p style=“font-size: large; text-align: centre;”>
            John Harvard
        </p>
        <p style=“font-size: medium; text-align: centre;”>
            Welcome to my home page!
        </p>
        <p style=“font-size: small; text-align: centre;”>
            Copyright &#169; John Harvard
        </p>
    </body>
</html>
```
As you can see we have used a `code` for the Copyright symbol as you can’t create this using your keyboard. There is a manual you can find online for all the symbols you are able to make.

As you can see, to change the size. You need to add a style tag to the paragraph tag like such:
```
<p style=“font-size: small;”>
```
To align text, you can do the following:
```
<p style=“text-align: centre;”>
```

The above is an ok way to do things, but there is a much better way to lay things out. That is by using `Divs` instead.

`div` = division

What we are going to do is change all the p tags to div tags.
```
<html lang”en”>

    <head>
        <title>home</title>
    </head>
    <body styles=“text-alignment: centre;”>
        <div style=“font-size: large;”>
            John Harvard
        </div>
        <div style=“font-size: medium;”>
            Welcome to my home page!
        </div>
        <div style=“font-size: small;”>
            Copyright &#169; John Harvard
        </div>
    </body>
</html>
```
What you can also see is that we have removed the repetition with the centre tag by moving the style to the body tag. This is because it is the parent tag, so any style parts you put here will cascade to the tags inside.

But what if you wanted to centre-align a section of the website but not all of it? Well, you can put the section you want to adjust inside a div like such:
```
<head>
    <title>home</title>
</head>
<body>
    <div style=“text-align: centre;”>
        <div style=“font-size: large;”>
            John Harvard
        </div>
        <div style=“font-size: medium;”>
            Welcome to my home page!
        </div>
        <div style=“font-size: small;”>
            Copyright &#169; John Harvard
        </div>
    </div>
</body>

```
This again still can be approved more by labelling the parts of the website accordingly, like such:
```
<head>
  <title>home</title>
</head>
<body style=“text-align: centre;”>
    <header style=“font-size: large;”>
        John Harvard
    </header>
    <main style=“font-size: medium;”>
        Welcome to my home page!
    </main>
    <footer style=“font-size: small;”>
        Copyright &#169; John Harvard
    </footer>
</body>
```
The problem with this still is that you shouldn’t really mix HTTP structure with CSS. Although there are some places that do, let’s take a look at separating them.
```
<head>
    <style>
        body
        {
            text-align: center;
        }

        header
        {
            font-size: large;
        }
			
        footer
        {
            font-size: small;
        }
    </style>
    <title>home</title>
</head>
<body>
    <header>
        John Harvard
    </header>
    <main>
        Welcome to my home page!
    </main>
    <footer>
        Copyright &#169; John Harvard
    </footer>
</body>
```
- `Type selector` = (body, header, footer)
- `Class selector` = your own keywords.
- `Id selector`
- `Attribute selector`

A `class` is when you create your own keyword that you can then add to a key to add the features. Here is an example of a `class`:
```
<head>
    <style>
        .centered
        {
            text-align: center;
        }

        .large
        {
            font-size: large;
        }
			
        .small
        {
            font-size: small;
        }
  </style>
  <title>home</title>
</head>
<body class=“centred”>
    <header class=“large”>
        John Harvard
    </header>
    <main class=“medium”>
        Welcome to my home page!
    </main>
    <footer class=“small”>
        Copyright &#169; John Harvard
    </footer>
</body>
```
Finally, let’s take a look at how we would move all the CSS to its own file so we can add and edit customisation there and apply them to the HTML later.

You have your HTML file called: `home.html`
And you have your CSS file called: `styles.css`

In your CSS file it looks like this:
```
.centered
{
    text-align: center;
}

.large
{
    font-size: large;
}
			
.small
{
    font-size: small;
}
```
And in your HTML file, it now looks like this:
```
<head>
    <link href=“styles.css” rel=“stylesheet”>
    <title>home</title>
</head>
<body class=“centred”>
    <header class=“large”>
        John Harvard
    </header>
    <main class=“medium”>
        Welcome to my home page!
    </main>
    <footer class=“small”>
        Copyright &#169; John Harvard
    </footer>
</body>
```
`Href` = the file you want to link in (in this case styles.css)
`Rel` = the relationship between them (in this case a stylesheet)

Let’s look at some more styles you can do.
```
<html lang=“en”>
    <head>
        <style>
            a
            {
                colour: red;            /* Changes text colour */
                text-decoration: none;	/* removes underlines and other. */
            }

            a:hover	/* when the user hovers over */
            {
                text-decoration: underline;
            }
        </style>
        <title>link</title>
    </head>
    <body>
        Visit <a href=“https:www.harvard.edu/">Harvard</a>
    </body>
</html>
```
Say you wanted to have two links though. The current CSS would change it for both anchor tags (a). But if we look at ID Selector, what we can do is give each link its own identification:
```
<html lang=“en”>
    <head>
        <style>

            #harvard
            {
                colour: #ff0000;	/* hexadecimal for red */
            }

            #yale
            {
                colour: #0000ff;	/* hexadecimal for blue */
            }

        </style>
        <title>link</title>
    </head>
    <body>
        Visit <a href=“https:www.harvard.edu/" id=“harvard”>Harvard</a> or <a href=“https:www.yale.edu/" id=“yale”>Yale</a>
    </body>
</html>
```
The only thing to mention with this is an ID is meant to be unique. So if you wanted to use these elements again, it’s probably best to do a class:
```
<html lang=“en”>
    <head>
        <style>

            .harvard
            {
	        colour: #ff0000;   /* hexadecimal for red */
	    }

	    .yale
	    {
		colour: #0000ff;   /* hexadecimal for blue */
	    }

	</style>
	<title>link</title>
    </head>
    <body>
    Visit <a href=“https:www.harvard.edu/" class=“harvard”>Harvard</a> or <a href=“https:www.yale.edu/" class=“yale”>Yale</a>
    </body>
</html>
```
Here are some more style details:

If you want to add a header to your table, you can do the following:
```
<body>
    <table>
	<thead>
	    <tr>
		<th>Name</th>		<!-- th = table header -->
		<th>Number</th>
	    </tr>
	</thead>
	<tbody>
	    <tr>
		<td>Yulia</td>
		<td>+1-617-495-1000</td>
	    </tr>
	    <tr>
		<td>David</td>
		<td>+1-617-495-1000</td>
	    </td>
	    <tr>
		<td>John</td>
		<td+1-949-468-2750</td>
	    </tr>
	</tbody>
    </table>
</body>
```
What people have done is make frameworks to help guide when it comes to styling with CSS.

A common library used for this is called “Bootstrap”. 

Here is the data sheet: getbootstrap.com

To get access to this, you need to add this link into the <head> part of your HTML code.
```
<head>
    <link href=“https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstap.min.css" rel=“stylesheet”>
</head>
<body>
    <table class=“table”>	<!-- to use their table style, add the table class. -->
	<thead>
	    <tr>
		<th scope=“col”>Name</th>	
		<th scope=“col”>Number</th>
	    </tr>
...
```
According to the documentation, not only do you need to add the link tag in the head. For tables, you also need to add class=“table” so that it knows which table to add the style to. You then also need to add scope=“col” to the column parts of the table so that it can also add those styles here.

If you read the document further, you will also see that you can add two parts to the class and do something like this that makes the table stripped.
```
<table class=“table table-stripped”>
```

-----

## JavaScript

###Conditionals

if statment:
```
if (x < y)
{

}
```
else statment:
```
if (x < y)
{

}
else
{

}
```
else if statment:
```
if (x < y)
{

}
else if (x > y)
{

}
else
{

}
```

-----

### Variables
Set a variable:
```
Let counter = 0;
```
Increasing a counter:
```
Counter = counter + 1;
Counter += 1;
Counter++;
```

-----

### Loops
for loop:
```
for (let I = 0; I < 3; I++)
{

}
```
while loop:
```
while (true)
{

}
```

-----

### Adding JavaScript to websites.
```
<html lang=“en”>
    <head>
	<script>
	    add code here
	</script>
	<title>
	    hello, title
	</title>
    </head>
</html>
```
Or you can add it via another file or URL like such:
```
<html lang=“en”>
    <head>
        <script src=“scripts.js”></script>	<!-- make sure to add the closing tag. -->

	<title>
	    hello, title
	</title>
    </head>
</html>
```
Or if you want to add script to the body, you can do this.
```
<html lang=“en”>
    <head>
        <title>
            hello, title
        </title>
    </head>
    <body>
        hello, body
        <script>
	    add code here
	</script>
    </body>
</html>
```
You can even add a file in the body too.
```
<head>
    <title>
        hello, title
    </title>
</head>
<body>
    hello, body
    <script src=“scripts.js”></script>	
</body>
```
Here are some events inside of a browser you can do with Javascript:
- `Blur`
- `Change`
- `Click`
- `Drag`
- `Focus`
- `Keyup`
- `Load`
- `Mousedown`
- `Mouseover`
- `Mouseup`
- `Submit`
- `Touchmove`
- `unload`
...

Let’s make a form using JavaScript on a website.
```
<!DOCTYPE html>

<html lang=“en”>
    <head>
	<script>

	    function greet( )
	    {
		let name = document.querySelector(‘#name’).value;
		alert(‘hello, ’ + name);
	    }

	</script>
	<title>hello</title>
    </head>
    <body>
	<form onsubmit=“greet( ); return false;”>
	    <input autocomplete=“off” autofocus id=“name” placeholder=“name” type=“text”>
	    <input type=“submit”>	<!-- gives you a submit button -->
	</form>
    </body>
</html>
```
As you can see, when doing `onsubmit` to call a function. The reason we do return false is because we don’t want to send anything to the server; we want to greet client-side.

So how do we actually create a function in JavaScript? Well, let’s take a look at the head script.

What is happening is we are setting a variable called name and setting the value to be the value of name, which can be found inside the document by using `querySelector( )`.

Then use an alert to display at the top of the screen the output.

The better way of doing this is to avoid mixing JavaScript into the CSS/HTML by adding a script into the body and setting an event listener on a specific part of the website, like a submit button, as the trigger. Like such:
```
<!DOCTYPE html>

<html lang=“en”>
    <head>
	<title>hello</title>
    </head>
    <body>
	<form>
	    <input autocomplete=“off” autofocus id=“name” placeholder=“name” type=“text”>
	    <input type=“submit”>	// gives you a submit button
	</form>
	<script>
			
	    function greet(event)
	    {
		let name = document.querySelector(‘#name’).value
		alert(‘hello, ‘ + name);
		event.preventDefault( );
	    }

	    let form = document.querySelector(‘form’);
	    form.addEventListener( ‘submit’, greet)
	</script>
    </body>
</html>
```
Here, to prevent the code from going to the server, what we do is take an input for `greet` as an event and set the event to prevent default, which is to query the server.

Now this code can be cleared up a bit because it is a bit unnecessary to create a variable just to be called once, so let’s first clean that up.
```
<!DOCTYPE html>

<html lang=“en”>
    <head>
	<title>hello</title>
    </head>
    <body>
	<form>
	    <input autocomplete=“off” autofocus id=“name” placeholder=“name” type=“text”>
	    <input type=“submit”>	<!-- gives you a submit button -->
	</form>
	<script>
	    function greet(event)
	    {
		alert(‘hello, ‘ + document.querySelector(‘#name’).value);
		event.preventDefault( );
	    }

	    let form = document.querySelector(‘form’);
	    form.addEventListener( ‘submit’, greet)
	</script>
    </body>
</html>
```
The other thing you can do with JavaScript is that if you are only using the function once, then you don’t need to give it a name. What you can do is create what’s known as a lambda function or anonymous function (a function with no name). Here is the updated code:
```
 <!DOCTYPE html>

<html lang=“en”>
    <head>
	<title>hello</title>
    </head>
    <body>
	<form>
	    <input autocomplete=“off” autofocus id=“name” placeholder=“name” type=“text”>
	    <input type=“submit”>	// gives you a submit button
	</form>
	<script>
	    let form = document.querySelector(‘form’);
	    form.addEventListener( ‘submit’, function(event) {
	    	alert(‘hello, ‘ + document.querySelector(‘#name’).value);
	    	event.preventDefault( );
	    });
	</script>
    </body>
</html>
```
And finally, for one last clean, you also don’t need the variable for form:
```
And finally, for one last clean, you also don’t need the variable for form:

<!DOCTYPE html>

<html lang=“en”>
    <head>
	<title>hello</title>
    </head>
    <body>
	<form>
	    <input autocomplete=“off” autofocus id=“name” placeholder=“name” type=“text”>
	    <input type=“submit”>	<!-- gives you a submit button -->
	</form>
	<script>
	    document.querySelector(‘form’).addEventListener( ‘submit’, function(event) {
		alert(‘hello, ‘ + document.querySelector(‘#name’).value);
		event.preventDefault( );
	    });
	</script>
    </body>
</html>
```
So what about if we move the code to the header? Well, you will run into some error messages because, as is the same with other languages, the code is executed top to bottom and so you are trying to execute the form function before the form has been mentioned. 

What you can do with JavaScript is add another event listener to tell the code to read all the code first, then come back and execute this line of code.
```
<!DOCTYPE html>

<html lang=“en”>
    <head>
	<script>
	    document.addEventListener(‘DOMContentLoaded’, function( ) {
		document.querySelector(‘form’).addEventListener( ‘submit’, function(event) {
		    alert(‘hello, ‘ + document.querySelector(‘#name’).value);
		    event.preventDefault( );
		});
	    });
	</script>
	<title>hello</title>
    </head>
    <body>
	<form>
	    <input autocomplete=“off” autofocus id=“name” placeholder=“name” type=“text”>
			<input type=“submit”>	<!-- gives you a submit button -->
	</form>
    </body>
</html>
```
Here is some code that updates every time the user enters a letter. It also checks if the variable has any value and prints something different on the page depending.
```
<html lang=“en”>

    <head>
	<script>
	    document.addEventListener(‘DOMContentLoaded’, function( ) {
		let input = document.querySelector(‘input’);
		input.addEventListener(‘keyup’, function(event) {
		    let name = document.querySelector(‘p’);
			if (input.value) {
			    name.innerHTML = `hello, ${input.value}`;
			}
			else {
			    name.innerHTML = ‘hello, whoever you are’
			}
		    });
		});
	</script>
    </head>
</html>
```
Here is some more code that gives you three buttons (R, G, B) and when one button is clicked, it changes the colour of the background depending on which one was clicked.
```
<body>
    <button id=“red”>R</button>
    <button id=“green”>G</button>
    <button id=“blue”>B</button>

    <script>
	let body = document.querySelector(‘body’);
	document.querySelector(‘#red’).addEventListener(‘click’, function( ) {
	    body.style.background = ‘red’;
	});

	document.querySelector(‘#green’).addEventListener(‘click’, function( ) {
	    body.style.background = ‘green’;
	});

	document.querySelector(‘#blue’).addEventListener(‘click’, function( ) {
	    body.style.background = ‘blue’;
	});
    </script>
</body>
```
-----
















