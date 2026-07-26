# ================= COMMANDS =================

def process_command(command):

    # ---------- TRANSLATE ----------

    if (
        "translate" in command
        or "translator" in command
        or "translation" in command
    ):

        translate_text()
        return True

    # ---------- HELLO ----------

    elif (
        "hello" in command
        or "hi" in command
        or "hey" in command
    ):

        speak("Hello, I am your AI smart glasses assistant")
        return True

    # ---------- TIME ----------

    elif (
        "time" in command
        or "what time is it" in command
        or "tell me the time" in command
    ):

        current_time = time.strftime("%I:%M %p")

        speak(f"The time is {current_time}")

        return True

    # ---------- CREATOR ----------

    elif (

        "who made you" in command
        or "who created you" in command
        or "who built you" in command
        or "who is your creator" in command
        or "who developed you" in command

    ):

        speak("I was created by Amin")

        return True

    # ---------- GOODBYE ----------

    elif (
        "stop" in command
        or "goodbye" in command
        or "exit" in command
        or "shutdown" in command
    ):

        speak("Goodbye")

        return False

    # ---------- DEFAULT AI ----------

    else:

        reply = ask_ai(command)

        speak(reply)

        return True
