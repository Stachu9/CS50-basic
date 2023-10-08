import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():

    rows = db.execute("SELECT * FROM birthdays;")

    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        if name and month and day and int(month) < 13 and int(month) > 0 and int(day) > 0 and int(day) < 30:
            db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?);", name, month, day)
        else:
            return render_template("index.html", rows = rows, alert_string = "Wrong type of data!")

        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html

        return render_template("index.html", rows = rows)

@app.route("/deregister", methods=["GET", "POST"])
def deregister():

    id = request.form.get("id")
    print(id)

    if id:
        db.execute("DELETE FROM birthdays WHERE id = ?;", id)

    return redirect("/")



