## 📚 CS50 week 9 - Flask

### Summary
- http-server
- Flask
- Forms
- Templates
- Request Methods
- Frosh Ims
- Flask and SQL
- Cookies and Sessions
- Shopping Cart
- Shows
- APIs
- JSON

---

- `Jinja documentation` = jinja.palletsprojects.com/templates/

Flask is a framework within Python that is used for back-end web development. 

`HTTP` = Hypertext Transfer Protocol

Http-server was used last week to create static websites that took the information from your code space and used it to create a website, whether that’s HTML, JavaScript, or even images. This code was all client-side, as all the JavaScript and all data were stored on the client’s side.

This week, by using Flask inside Python, we can create server-side websites where the browser will be talking to the server to get the information it’s supposed to be displaying, as well as things like server-side authentication where we can check passwords and other information against a SQL database. 

The other benefit is that we will be able to dynamically make web pages instead of needing to write each page of the website each time something changes. We can give Python using CSS and HTML some prefixes and fill in the data, and it will `dynamically` make the website.

This is known as a dynamic website.

From here on out, everything after the TLD of a URL is going to be known as the path that the browser is requesting from the server.
```
https://www.example.com/path
```
A `path` relates to a specific file or folder under a URL.

A route generically means what path do you want to select on a web server? What this means is you don’t specifically need a file or folder to exist, but using Python and such, you can accept other information, for example, a search query.
```
https://www.example.com/route?key=value
```
If you wanted multiple inputs or key-values, you can do the following:
```
https://www.example.com/route?key=value&key=value
```
So how does this request get to the server?

Using the `GET` method. What means that when you submit that `form`, so to speak. You are signing the envelope with `GET` to go get some information from the server. Such as:
```
GET /search?q=cats HTTP/2
Host: www.google.com
```

The next issue we face is how do you get the computer and server to receive the information sent and go through each line and collect the data and…

That’s where Flask comes in. Flask is a framework library for Python. It saves us time as the programmer to figure out how to read the data inside the envelopes and figure out what needs to be done.

After today, instead of using http-server. We are now going to start using ‘flask run’. This will still start a server, but more of a smart server. It will take your Python code to generate those webpages instead of HTML code.

When using Flask, it is required that you use at least these two files:
1. App.py
2. Requirements.txt

Here is some Python code that creates the simplest webpage:
```
from flask import Flask

App = Flask(__name__)	- the name here means this file here.

@app.route(“/“)			-This is known as a decorator.
Def index( ):
	return “hello, world”
```
A `decorator` is a function that wraps one function inside another.

Let’s now create a dynamic website for the first time using Python:
Head to vs code to see this under the folder hello.

Now, if you want to start the webpage, you need to use:
```
flask run
```
Now we have added HTML under the return tag to allow us to use HTML on the website like such:
```
@app.route("/")
def index():
    return '<DOCTYPE html><html lang="en"><head><title>hello, title</title></head><body>hello, body</body></html>’
```
What we are going to do now instead is move our HTML into its own file so it’s not cluttering our Python file, and then we are going to use a tool called “Render_Template” that will send the HTML to the web page.

So to begin, let’s create a folder called templates inside the current folder. Then we will cd into templates and the command prompt will look like the following:
```
Hello/templates/ $
```

Inside this folder is where we will place the HTML file. Now we have the HTML file written and in the templates folder. At the top of the app.py file, next to import flask, we also need to add `render_template` like such:
```
from flask import Flask, render_template
```
What this does is, as the name states, and that is to render templates for you.

The next thing we need to do is, in a variable, tell `render_template` what HTML file to render:
```
@app.route("/")
def index():
    html = render_template("index.html")
    return html
```
We don’t need to create a variable in this example as we are only setting it then using it once, but it’s good to know how to do it.
```
@app.route("/")
def index():
    return render_template("index.html")
```

Let’s look at taking an input and getting the page to say hello, then a (placeholder) that can then be changed into an answer from the user.

The syntax for a placeholder with Flask is to use two curly brackets. Here is what that update looks like in our HTML:
```
    <body>
        hello, {{ placeholder }}
    </body>
```
What we then need to do is in our `app.py` is import request.
Request will give you access to all the HTML perimeters (inputs and such)
```
from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/")
def index():
    name = request.args["name"]
    return render_template("index.html", placeholder=name)
```
This is the benefit of using this framework as it saves us the work of reading that envelope and all its data. Instead, we use this variable `request.args` which gives us a Python dictionary with all the key-value pairs.

The example above still isn’t the perfect way to do this as if you don’t manually write in the URL `?name=test` then the browser isn’t going to take any value and therefore the site won’t work and you will get a Bad Request page instead.

So what we need to do instead is add an if statement to say if there is a name key inside of request.args then create a variable called name that can then write over the placeholder. Else if there is no key, then set name to a default value like world that will then replace the placeholder:
```
@app.route("/")
def index():
    if "name" in request.args:
        name = request.args["name"]
    else:
        name = "world"
    return render_template("index.html", placeholder=name)
```
So what about if you wanted multiple placeholders across your site? It’s no good using the name placeholder all over the place. What you can do is almost the same as variables and give it a name for what it is you want there. So in this example, in the HTML file, we change the word placeholder to “name”.
```
	<body>
        hello, {{ name }}
    </body>
```
Then the next thing we need to change is the code in the Python file to replace the correct keyword. Like such:
```
@app.route("/")
def index():
    if "name" in request.args:
        name = request.args["name"]
    else:
        name = "world"
    return render_template("index.html", name=name)
```
There is, of course, a better way still of doing this. Thankfully, requests come with another feature called “get” that checks for key-value pairs, and if there is no value, then you can assign a generic value to be used instead. Here is an example:
```
@app.route("/")
def index():
    name = request.args.get("name", "world")
    return render_template("index.html", name=name)
```

Let’s now, instead of having the user add value to the URL, let’s look at making a form to take data from a user’s input and how we would deal with that on the backend.

First things first, let’s create a form in HTML.
```
<body>
        <form action="/greet" method="get">
            <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
            <button type="submit">Greet</button>
        </form>
    </body>
```
As you can see, I have added a form element that has autocomplete off so that it doesn’t remember previous entries. Autofocus is mentioned so that the box is automatically focused on. Name variable - “name” and there is a placeholder in the form called Name so that the user knows what to input here. 

The other part that is new is the action part of the form. What action does is it allows us to use the GET feature to retrieve data from the website. We could use the POST key word which would be a secure way to transfer the information instead. 

Now what we need to do is to create a greet function in our py file so that the website knows what to do and return when the website goes to /greet.
```
@app.route("/")
def index():
    return render_template("index.html")


@app.route("/greet")
def greet():
    name = request.args.get("name", "world")
    return render_template("greet.html", name=name)
```
Now you can see we are going to make a new template called “greet.html”.

Just for context, if we don’t create a greet.html file. When we try using the feature on the website, we will get an Internal Server Error (code 500). This means you did something wrong with your code and something is missing. You can see what the issue is by going back to your terminal and you will see a hint: `jinja2.exceptions.TemplateNotFound: greet.html`

Jinja is another library that is used inside Flask. Jinja is a templating library that handles everything inside the templates directory.

Let’s create the template to get rid of this error.
```
<!DOCTYPE html>

<html lang="en">

    <head>
        <title>greet</title>
    </head>

    <body>
        hello {{ name }}
    </body>

</html>
```
If you do cd . . you can go backwards in your directory.

The issue we now have with our website is that it is not responsive, so if you were to move to mobile, you would notice that the search bar is super small as the site is not re-adjusting for each device.

How can we fix this? Well, in the head, we can add a tag called meta and set the name to viewport and set the content to scale with the device width. Like this:
```
    <head>
        <meta name="viewport" content="initial-scale=1, width=device-width">
        <title>hello, title</title>
    </head>
```
This still isn’t the best way because you would need to copy and paste this to all of your HTML pages, and as we know, copying and pasting is not the best method. The thing is that’s not all the code that’s repeated across pages, so can we fix that too?

What we can do is create one more file inside templates called layout.html. What this does is create almost a framework HTML page for us, and what we can do is set defaults such as the scaling feature. We can also use Jinja to create a body placeholder that we can use to place the body of another HTML file.
```
<!DOCTYPE html>

<html lang="en">

    <head>
        <meta name="viewport" content="initial-scale=1, width=device-width">
        <title>hello</title>
    </head>


    <body>
        {% block body %}{% endblock %}
    </body>
</html>
```
As you can see, we use {%block body%} and {%endblock%} to mark out this body placeholder.

You can use whatever variable name you want where it says body, but the rest needs to be kept the same as technically it is a block. 

So now let’s look at what you need to do to the other HTML files to bring the body over to this template page. 
```
{% extend "layout.html %}

(% block body %)

    <form action="/greet" method="get">
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
        <button type="submit">Greet</button>
    </form>

{& endblock %}
```
As you can see, what we have done is told this page to extend layout.html and then used the same block tags to tell the page what is being replaced and where.

We can do the other pages like greet like this:
```
{% extends "layout.html" %}

{% block body %}
    hello {{ name }}
{% endblock %}
```
And that’s it, you don’t need anything else in app.py as it is using the template to create the webpages. 


So that’s GET requests. Let’s now look at some more like POST.

POST treats your data more privately by putting it further down the envelope that is travelling between the server and webpage and, more importantly, it doesn’t display your input in the URL.

So let’s change the current GET function (see above) for our hello website to a push function.
```
    <form action="/greet" method="post">
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
        <button type="submit">Greet</button>
    </form>
```
The only issue with this is that in app.py, we are currently using @app.route to collect the data. But this is only supported for GET. But what we can do is tell Flask that we want to support PUSH. What we can do is add a Python list to the app.route that tells Flask what “methods” we want to use. You can add both GET and PUSH, which is what you will see in the below example, but if all you are doing is using PUSH, then you only need to add PUSH. 
```
@app.route("/greet", methods=["GET", "POST"])
def greet():
    name = request.args.get("name", "world")
    return render_template("greet.html", name=name)

There is also one more thing we need to adjust. “Get” values are stores in request.args, but “Post” values are stored in request.form.

@app.route("/greet", methods=["POST"])
def greet():
    name = request.form.get("name", "world")
    return render_template("greet.html", name=name)
```
That is how you would get and post.

Let’s now look at how we could recreate all of this with fewer lines of code. Now, this isn’t always the best method, but if you needed to shrink the amount of lines of code, then this is how you would do it.

What we are going to do is, inside of app.py, we are going to remove the need for two routes. We are going to add an if statement to the original / route, which is what the browser will use as default, and add the get and post list to accept inputs. Then the if statement will decide if a push has happened, and if it has, then do the same as before; else, render index.html. Let’s see what that looks like:

#### Before
```
@app.route("/")
def index():
    return render_template("index.html")


@app.route("/greet", methods=["POST"])
def greet():
    name = request.form.get("name", "world")
    return render_template("greet.html", name=name)
```
#### After
```
@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form.get("name", "world")
        return render_template("greet.html", name=name)
    else:
        return render_template("index.html")
```
Lastly, we also need to change the action part of the index.html from greet to the default /. What we can actually do is remove action altogether if we wanted, as / is the default value.
```
    <form method="post">
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
        <button type="submit">Greet</button>
    </form>
```
What else can we do with Jinja? Well, let’s look at doing things conditionally. Let’s look at removing the need to have default values on the if statement and place it closer to the user on the form. Here is the updated app.py to have removed the need for “world” and also the no longer need for setting the name variable as we can move that to the line below.
```
@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        return render_template("greet.html", name=request.form.get("name"))
    else:
        return render_template("index.html")
```
Now let’s look at updating greet.html to allow the default value here by doing a conditional like this:
```
{% block body %}

    hello,
    {% if name %}
        {{ name }}
    {% else %}
        world
    (% endif %)

{% endblock %}
```
That is all for the basic web page, now lets look at something more complex.

-----

### Frosh IMs

`Select` = equivalent to a drop down normally seen on the web.

Images for these types of websites should be in a folder called `static`.

What we have been implementing is a controller, as it controls everything about your application. The part that the controller interacts with, and so does the user, is the “view”. And the final piece we added, which was the database, is known as a model.

This is all known as MVC (Model View Controller).

Let’s look at logins so we can put some of the import information behind a login page.

What we are going to also want to do is make a way that the browser remembers you logged in so you don’t need to every time you load the webpage. The way we are going to do this is using cookies.

What we are trying to achieve is for the envelope to look like this:
```
HTTP/2 200
Content-type: text/html
Set-Cookie: session=value
```
What the website will then do to confirm the user is in the header of the GET function when talking to the server is:
```
GET / HTTP/2
Host: accounts.google.com
Cookie: session=value
```
This is know as a session.

When adding a database, use db = SQL(“sqlite:///nameofdatabase.db")

Index.html is the homepage.

### API

Application Program Interface.

In index.html we have some code that looks like this:
```
{% extends “layout.html” %}

{% block body %}

	<input autocomplete=“off” autofocus placeholder=“Query” type=“search”>

	<ul></ul>

	<script>

		let input = document.querySelector(‘input’);
		input.addEventListener(‘input’, async function( ) {
			let response = await fetch(‘/search?q=‘ + input.value);
			let shows = await response.text( );
			document.querySelector(‘ul”).innerHTML = shows;
		});
	</script>

{% endblock %}
```
When using APIs, you don’t really want to send back HTML data; what you want is to collect the raw data. To do this, we are going to need a new tool called JSON.

`JSON` = Java Script Object Notation.

Using this, we can send back something similar to a Python dictionary called objects.

We can use jsonify from Flask to turn any list into a JSON list.
