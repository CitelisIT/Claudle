import React, { Fragment, useContext } from "react";
import { Popover, Transition } from "@headlessui/react";
import { MenuIcon, XIcon } from "@heroicons/react/outline";
import { SettingsContext } from "../App";

export default function Sidebar() {
  const settingsContext = useContext(SettingsContext);
  const disabled = settingsContext.gameState === 0 ? false : true;
  return (
    <Popover className="">
      <Popover.Button className="flex items-center justify-center">
        <MenuIcon className="w-6 h-6 text-gray-200 md:w-8 md:h-8" />
      </Popover.Button>
      <Transition
        as={Fragment}
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
            <li className="py-2 text-xl text-gray-200 hover:bg-gray-700">
              <button
                onClick={() => {
                  settingsContext.setLang("english");
                }}
                {...{ disabled }}
              >
                <span className="mx-8 my-2">English</span>
              </button>
            </li>
            <li className="py-2 text-xl text-gray-200 hover:bg-gray-700">
              <button
                onClick={() => {
                  settingsContext.setLang("francais");
                }}
                {...{ disabled }}
              >
                <span className="mx-8 my-2">Français</span>
              </button>
            </li>
          </ul>
        </Popover.Panel>
      </Transition>
    </Popover>
  );
}
