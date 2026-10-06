# Git/Github Guide

## What Git and GitHub actually are

**Git** is a program on your computer. It takes snapshots of your project so you
can see what changed, go back to an earlier version, and work on an idea without
breaking what already works.

**GitHub** is a website that stores copies of Git projects online. It's how your
code gets off your laptop so mentors can read it, comment on it, and help.

A useful comparison: Git is like the version history in Google Docs, except you
decide when each save point happens and you write a note explaining it. GitHub is
the part where the document lives in the cloud and other people can see it.

---

## Create your GitHub account

Go to **[github.com/signup](https://github.com/signup)** and make an account.

- **Use an email you'll keep.** Not a school email that gets deleted after you
  graduate.

---

## Installing Git on Windows

1. Go to **[git-scm.com/download/win](https://git-scm.com/download/win)**. The
   download starts automatically — pick the 64-bit standalone installer if it
   doesn't.
2. Run the installer. It asks a *lot* of questions. **Accept the defaults for
   all of them** — they're sensible, and you can change things later.

   Two screens worth noticing as you click through:
   - **"Choosing the default editor used by Git"** — if VS Code is already
     installed, select *Use Visual Studio Code as Git's default editor*. If not,
     leave the default; it won't matter for what we're doing.
   - **"Adjusting your PATH environment"** — leave it on *Git from the command
     line and also from 3rd-party software* (the recommended middle option).

3. When it's done, open **Git Bash** from the Start menu. This is the terminal
   you'll use for every Git command in this program — not Command Prompt, not
   PowerShell. Git Bash behaves the same way the Mac terminal does, so
   instructions written for either one will work for you.
4. Type this and press Enter:

   ```bash
   git --version
   ```

   You should see a version number.

---

## First-time setup

Git stamps your name and email onto every snapshot you make, so it knows who did
what. You will have to only set these up once.

In Terminal (macOS) or Git Bash (Windows), run both lines — substituting your own
name and the email you used for GitHub:

```bash
git config --global user.name "Your Name"
git config --global user.email "you@example.com"
```

Then set the default branch name to `main`, which is what GitHub uses:

```bash
git config --global init.defaultBranch main
```

Check that it took:

```bash
git config --global --list
```

You should see your name and email in the output.

> **Use the same email as your GitHub account.** If they don't match, your
> commits won't be linked to your profile on GitHub — they'll show up as
> belonging to nobody.

---

## The words you'll keep hearing

You don't need to memorize these. Come back when a word stops making sense.

| Word | What it means |
|---|---|
| **Repository** (repo) | A project folder that Git is tracking. This project lives in one. |
| **Clone** | Download a copy of a repo from GitHub onto your computer. |
| **Commit** | One saved snapshot, with a note explaining what changed. |
| **Branch** | A parallel line of work. Lets you try something without touching the working version. Basically like another save file/version. |
| **`main`** | The primary branch that should contain working code |
| **Remote** | The copy of the repo that lives on GitHub. Usually nicknamed `origin`. |
| **Push** | Send your commits up to GitHub. |
| **Pull** | Bring down commits other people pushed. |
| **Pull request** (PR) | A request to merge your branch into `main`, so others can review it first. |
| **Merge** | Combine one branch's changes into another. |

---

## Cheat sheet

Print this, or keep the tab open.

```bash
# Starting work
git checkout main            # switch to the main branch
git pull                     # get the latest changes
git checkout -b my-branch    # create a branch and switch to it

# While working
git status                   # what's changed? what branch am I on?
git diff                     # show me exactly what I changed
git add .                    # stage all changes
git commit -m "message"      # save a snapshot

# Sharing work
git push -u origin my-branch # first push of a new branch
git push                     # every push after that

# Looking around
git log --oneline            # list recent commits
git branch                   # list branches, marking the current one
git checkout main            # switch back to main
```

---

[← Back to the main guide](../README.md)
