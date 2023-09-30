-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Read crime scene reports:
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";
-- Read witnesses interviews:
SELECT name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";
-- Check Legget Street ATM transaction before robbery
SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
-- Check person id, who withdrawed money from ATM
SELECT person_id, creation_year, amount FROM bank_accounts JOIN (SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw") AS x ON bank_accounts.account_number = x.account_number;
-- Check names, phone numbers, passports, lcense plates, account creation year who withdrawed money from ATM
SELECT name, phone_number, passport_number, license_plate, creation_year, amount FROM people JOIN (SELECT person_id, creation_year, amount FROM bank_accounts JOIN (SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw") AS x ON bank_accounts.account_number = x.account_number) AS z ON people.id = z.person_id;
-- Check logs from bakery parking
SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 AND minute >= 15 AND activity = "exit";
-- Check phone calls
SELECT caller, receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
-- Checkk Fiftyville airport id
SELECT id FROM airports WHERE full_name LIKE "%iftyville%";
-- Check first flight from fiftyville on 29.07
SELECT id, destination_airport_id, hour, minute FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE full_name LIKE "%iftyville%") AND year = 2021 AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1;