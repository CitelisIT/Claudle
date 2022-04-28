import { Fragment, useContext, useState } from "react";
import { Popover, Transition } from "@headlessui/react";
import { XIcon } from "@heroicons/react/outline";
import { SettingsContext } from "../App";

export default function Sidebar() {
  const settingsContext = useContext(SettingsContext);
  const disabled = settingsContext.gameState === 0 ? false : true;
  const [isShowing, setIsShowing] = useState(false);
  const flag =
    settingsContext.lang === "english"
      ? "./Flag_of_the_United_Kingdom.svg"
      : "./Flag_of_France.svg";
  return (
    <Popover
      className=""
      onClick={() => {
        setIsShowing((isShowing) => !isShowing);
      }}
    >
      <Popover.Button className="flex items-center justify-center">
        <img src={flag} alt="Flag" className="h-6 text-gray-200 md:w-8 " />;
      </Popover.Button>
      <Transition
        as={Fragment}
        show={isShowing}
        enter="transform transition ease-in-out duration-300"
        enterFrom="-translate-x-full"
        enterTo="translate-x-0"
        leave="transform transition ease-in-out duration-300"
        leaveFrom="translate-x-0"
        leaveTo="-translate-x-full"
      >
        <Popover.Panel className="absolute bottom-0 left-0 flex flex-col items-start justify-start h-[calc(100%-4rem-1px)] gap-12 py-8 bg-gray-900 border-r border-gray-600">
          <div className="flex items-center justify-center gap-8 mx-8">
            <h1 className="text-2xl font-semibold text-gray-200">
              Mode de Jeu
            </h1>
            <Popover.Button>
              <XIcon className="w-8 h-8 text-gray-200" />
            </Popover.Button>
          </div>
          <ul className="w-full grow">
            <li className="flex items-center justify-start py-2 text-xl text-gray-200 hover:bg-gray-700">
              <span className="flex items-center justify-center w-6 mx-4 text-3xl">
                {settingsContext.lang === "english" ? "•" : ""}
              </span>
              <button
                className="flex items-center justify-center gap-4 my-2"
                onClick={() => {
                  settingsContext.setLang("english");
                }}
                {...{ disabled }}
              >
                <span> English</span>
                <img
                  src="./Flag_of_the_United_Kingdom.svg"
                  alt="Flag"
                  className="h-5 md:w-8 "
                />
              </button>
            </li>
            <li className="flex items-center justify-start py-2 text-xl text-gray-200 selected: bg-grey-700 hover:bg-gray-700">
              <span className="flex items-center justify-center w-6 mx-4 text-3xl">
                {settingsContext.lang === "francais" ? "•" : ""}
              </span>
              <button
                className="flex items-center justify-center gap-4"
                onClick={() => {
                  settingsContext.setLang("francais");
                }}
                {...{ disabled }}
              >
                <span>Français</span>
                <img
                  src="./Flag_of_France.svg"
                  alt="Flag"
                  className="h-5 md:w-8 "
                />
              </button>
            </li>
            <li className="flex items-center justify-start py-2 text-xl text-gray-200 selected: bg-grey-700 hover:bg-gray-700">
              <span className="flex items-center justify-center w-6 mx-4 text-3xl">
                {settingsContext.lang === "cloclo" ? "•" : ""}
              </span>
              <button
                className="flex items-center justify-center gap-4"
                onClick={() => {
                  settingsContext.setLang("cloclo");
                }}
                {...{ disabled }}
              >
                <span>Claude François</span>
                <img
                  src="./ClaudeFrancois.jpg"
                  alt="Flag"
                  className="h-5 md:w-8 "
                />
              </button>
            </li>
          </ul>
        </Popover.Panel>
      </Transition>
    </Popover>
  );
}
