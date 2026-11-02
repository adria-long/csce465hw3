# AI Usage Description

**Tool/model and date:** ChatGPT (OpenAI), October 29-November 2, 2026. OpenClaw agent (`protected.gpt-4o`).

**Purpose:** I used ChatGPT to help me understand the assignment, work through debugging steps, and do a grammar overview of my report. I used the OpenClaw agent to test the adversarial webpage in Task 2.

**AI Conversation Log files:** I will submit the relevant ChatGPT prompts and responses as a separate conversation log, with any sensitive information removed.

**What I used:** ChatGPT helped me understand how to work with GDB, debug the payload, understand how to set up the OpenClaw skill, and interpret the failed webpage request. I also used it for a grammar overview of my report.

**What I changed:** I used the debugging guidance to make adjustments for my own files and environment. I checked the 136-byte offset and `win()` address in GDB and revised my report based on my test results.

**How I tested it:** I checked the binary with `checksec` and GDB, ran the payload against the parser, and verified that the marker file was created. I tested the skill wrapper with an allowed file and a file outside `inbox/`. I also ran the OpenClaw agent.

**One error, limitation, or rejected suggestion:** OpenClaw could not fetch the local webpage because the address was blocked. The agent never received the webpage instructions or ran the vulnerable parser, so I reported that the Task 2 attack did not complete.