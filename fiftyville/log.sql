-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Read crime scene reports:
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";
-- Read witnesses interviews:
SELECT name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";
-- Check Legget Street ATM transaction before robbery
SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
-- Check names, who withdrawed money from ATM
